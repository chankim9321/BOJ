package dispatch

import (
	"context"
	"log"
	"time"

	pb "backend/protocol"
	cs "backend/protocol/client_side"

	grpc "google.golang.org/grpc"
)

func GetFileList(senderAddr string, recvAddr string) (*pb.FileInfoList, error) {
	var conn *grpc.ClientConn

	conn, err := grpc.Dial(recvAddr, grpc.WithInsecure(), grpc.WithTimeout(5*time.Second))
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()

	client := cs.NewClient(conn)
	var fileList *pb.FileInfoList
	fileList, err = client.GetFileList(context.Background(), senderAddr, recvAddr)
	if err != nil {
		fileList = nil
		return fileList, err
	}

	return fileList, nil
}
