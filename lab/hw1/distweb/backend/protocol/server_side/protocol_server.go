package server_side

import (
	"context"
	"io"
	"log"
	"os"
	"strings"

	db "backend/databases"
	util "backend/util"

	pb "backend/protocol"
)

type FileTransferServer struct {
	pb.FileTransferServiceServer
}

const chunkSize = 512 * 1024

func (s *FileTransferServer) UploadFile(stream pb.FileTransferService_UploadFileServer) error {
	fileChunks := []byte{}
	var filename string = ""
	var dstPort string = ""
	for {
		chunk, err := stream.Recv()
		if err == io.EOF {
			break
		}
		if err != nil {
			log.Fatal(err)

		}
		// 수신한 청크를 청크 슬라이스에 추가
		fileChunks = append(fileChunks, chunk.Contents...)
		filename = chunk.FileName
		dstPort = strings.Split(chunk.NodeAddress, ":")[1]
	}
	// 청크 슬라이스를 로컬 파일로 생성
	localStoragePath := util.GetStoragePathByMapping(dstPort)
	file, err := os.Create(localStoragePath + filename)
	if err != nil {
		return err
	}
	defer file.Close()
	_, err = file.Write(fileChunks)
	if err != nil {
		return err
	}

	// db Handling
	log.Println("db handling server test")
	dbAddress := util.GetDBaddressByMapping(dstPort) // get db server addr

	conn, err := db.GetMongoConnection(dbAddress)
	if err != nil {
		log.Fatal("DB connection failed : ", err)
	}
	err = db.WriteFileOnMongoDB(conn, localStoragePath, filename)
	if err != nil {
		log.Fatal("DB Write failed : ", err)
	}

	err = os.Remove(localStoragePath + filename)
	if err != nil {
		log.Fatal("Failed to remove local file : ", err)
	}
	return nil

}

// 클라이언트에서 받은 메타데이터를 이용하여 db에서 파일을 가져와 쓴 후 클라이언트 측에 청크단위로 전송한다
func (s *FileTransferServer) GetFile(metadata *pb.FileMetadata, stream pb.FileTransferService_GetFileServer) error {
	fileID := metadata.FileID
	fileName := metadata.FileName
	recvAddr := metadata.Recv
	senderAddr := metadata.Sender
	dstPort := strings.Split(recvAddr, ":")[1]
	dbAddress := util.GetDBaddressByMapping(dstPort)
	localStoragePath := util.GetStoragePathByMapping(dstPort)

	// db Handling
	conn, err := db.GetMongoConnection(dbAddress)
	if err != nil {
		log.Fatal("DB connection failed : ", err)
	}
	err = db.DownloadFileFromMongoDB(conn, localStoragePath, fileID)
	if err != nil {
		log.Fatal("DB Download failed : ", err)
	}

	// 파일 청크 읽어서 전송
	log.Println("ss_filename", fileName)
	file, err := os.Open(localStoragePath + fileName)
	if err != nil {
		log.Fatalf("Failed to open file: %v", err)
	}
	defer file.Close()

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
			ServiceType: "Download",
			NodeAddress: senderAddr,
			DNS:         "",
		}
		err = stream.Send(chunk)
		if err != nil {
			log.Fatalf("Failed to send chunk: %v", err)
		}
	}
	err = os.Remove(localStoragePath + fileName)
	if err != nil {
		log.Fatal(err)
	}
	return nil
}
func (s *FileTransferServer) GetFileList(ctx context.Context, metadata *pb.DispatchInfo) (*pb.FileInfoList, error) {
	// DB Handling
	recvAddr := metadata.Recv
	dstPort := strings.Split(recvAddr, ":")[1]
	dbAddress := util.GetDBaddressByMapping(dstPort)
	conn, err := db.GetMongoConnection(dbAddress)
	if err != nil {
		log.Fatal("DB connection failed : ", err)
	}
	// GOT FILE LIST DATA
	fileListInfo, err := db.GetFileListFromMongoDB(conn)
	if err != nil {
		log.Fatal("FileTransferServer -> GetFileList Error: ", err)
	}
	return fileListInfo, nil
}
