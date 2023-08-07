package dispatch

import (
	db "backend/databases"
	cs "backend/protocol/client_side"

	"context"
	"log"
	"time"

	grpc "google.golang.org/grpc"
)

// 현재 노드에서 존재하는 파일을 다른 노드로 파일 전송
func UploadRequestToNode(metadata FileUploadRequestMetadata) error {
	var conn *grpc.ClientConn

	// Connect to Receiver gRPC Server
	conn, err := grpc.Dial(metadata.RecvAddress, grpc.WithInsecure(), grpc.WithTimeout(5*time.Second))
	if err != nil {
		log.Printf("did not connect: %v\n", err)
		return nil
	}
	// RPC call
	client := cs.NewClient(conn)
	client.UploadFile(
		context.Background(),
		metadata.FileName,
		metadata.FilePath+metadata.FileName,
		metadata.RecvAddress,
		metadata.SenderAddress,
		"exampleDNSName",
	)
	return nil
}

// 현재 노드에서 받은 파일을 현재 노드의 DB로 파일 업로드
func UploadRequest(metadata FileUploadRequestMetadata) error {
	localStoragePath := metadata.FilePath
	fileName := metadata.FileName

	// DB connection
	conn, err := db.GetMongoConnection()
	if err != nil {
		log.Fatal("DB Connection Failed: ", err)
	}
	err = db.WriteFileOnMongoDB(conn, localStoragePath, fileName)
	if err != nil {
		log.Fatal("DB Write failed : ", err)
	}
	return nil
}
