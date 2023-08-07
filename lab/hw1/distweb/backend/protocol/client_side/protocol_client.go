package client_side

import (
	"context"
	"io"
	"log"
	"os"
	"strings"

	pb "backend/protocol"
	util "backend/util"

	grpc "google.golang.org/grpc"
)

const chunkSize = 512 * 1024 // 512KB
type Client struct {
	client pb.FileTransferServiceClient
}

func NewClient(conn grpc.ClientConnInterface) Client {
	return Client{
		client: pb.NewFileTransferServiceClient(conn),
	}
}
func (c *Client) UploadFile(ctx context.Context, fileName string, filePath string, recvAddress string, senderAddress string, DNSname string) {
	// 스트림 요청
	stream, err := c.client.UploadFile(ctx)
	if err != nil {
		log.Printf("Failed to create stream: %v\n", err)
		return
	}

	// 전송할 파일 열기
	senderPort := strings.Split(senderAddress, ":")[1]
	senderStorage := util.GetStoragePathByMapping(senderPort)
	file, err := os.Open(senderStorage + fileName)
	if err != nil {
		log.Fatalf("Failed to open file: %v", err)
	}
	defer file.Close()

	// 파일 청크 읽어서 전송
	buffer := make([]byte, chunkSize)
	for {
		bytesRead, err := file.Read(buffer)
		if err == io.EOF {
			break
		}
		if err != nil {
			log.Fatalf("Failed to read file: %v", err)
		}
		chunk := &pb.FileChunk{
			Contents:    buffer[:bytesRead],
			FileName:    fileName,
			ServiceType: "ADD",
			NodeAddress: recvAddress,
			DNS:         DNSname,
		}
		err = stream.Send(chunk)
		if err != nil {
			log.Fatalf("Failed to send chunk: %v", err)
		}
	}
	// 파일 전송 완료 후 스트림 종료
	_, err = stream.CloseAndRecv()
	if err != io.EOF {
		log.Fatalf("Failed to receive response: %v", err)
	}
	log.Println("File transfer completed")
}
func (c *Client) GetFile(ctx context.Context, fileID string, fileName string, fileSize string, recvAddress string, senderAddress string) error {
	log.Println("cs_fileName", fileName)
	metadata := &pb.FileMetadata{
		FileID:   fileID,
		FileName: fileName,
		FileSize: fileSize,
		Sender:   senderAddress,
		Recv:     recvAddress,
	}
	stream, err := c.client.GetFile(ctx, metadata) // 원격지에서는 파일 청크 스트림을 반환
	if err != nil {
		log.Fatalf("failed to request file transfer: %v", err)
	}
	// recv file chunk
	fileChunks := []byte{}
	for {
		chunk, err := stream.Recv()
		if err == io.EOF {
			log.Println("File transfer complete")
			break
		}
		if err != nil {
			log.Fatalf("failed to receive data: %v", err)
		}
		fileChunks = append(fileChunks, chunk.Contents...)
	}
	// write local

	localStoragePath := util.GetStoragePathByMapping(strings.Split(senderAddress, ":")[1])
	file, err := os.Create(localStoragePath + metadata.FileName)
	if err != nil {
		return err
	}
	defer file.Close()
	_, err = file.Write(fileChunks)
	if err != nil {
		return err
	}
	return nil
}
func (c *Client) GetFileList(ctx context.Context, senderAddr string, recvAddr string) (*pb.FileInfoList, error) {
	metadata := &pb.DispatchInfo{
		Sender: senderAddr,
		Recv:   recvAddr,
	}
	response, err := c.client.GetFileList(ctx, metadata) // 원격지에 호출
	if err != nil {
		log.Println("원격 서버와 연결이 끊김")
		response = nil
		return response, err
	}
	return response, nil
}
