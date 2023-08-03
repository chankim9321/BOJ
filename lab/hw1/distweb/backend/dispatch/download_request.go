package dispatch

import (
	"context"
	"log"
	"strings"
	"time"

	db "backend/databases"
	cs "backend/protocol/client_side"
	util "backend/util"

	grpc "google.golang.org/grpc"
)

func DownloadRequest(metadata FileDownloadRequestMetadata) error {
	dstPort := strings.Split(metadata.RecvAddress, ":")[1]
	localStoragePath := metadata.FilePath
	fileID := metadata.FileID
	dbAddr := util.GetDBaddressByMapping(dstPort)
	// DB connection
	conn, err := db.GetMongoConnection(dbAddr)
	if err != nil {
		log.Fatal("DB connection failed : ", err)
	}
	err = db.DownloadFileFromMongoDB(conn, localStoragePath, fileID)
	if err != nil {
		log.Fatal("DB Write failed : ", err)
	}
	return nil
}

func DownloadRequestToNode(metadata FileDownloadRequestMetadata) error {
	var conn *grpc.ClientConn
	// Connect to Receiver gRPC Server
	conn, err := grpc.Dial(metadata.RecvAddress, grpc.WithInsecure(), grpc.WithTimeout(5*time.Second))
	if err != nil {
		log.Println("can't connect to " + metadata.RecvAddress)
	}
	defer conn.Close()
	// RPC call
	client := cs.NewClient(conn)
	// 서버는 DB에서 파일을 받은 후 클라이언트에 스트림을 연결
	err = client.GetFile(
		context.Background(),
		metadata.FileID,
		metadata.FileName,
		"test empty",
		metadata.RecvAddress,
		metadata.SenderAddress,
	)
	if err != nil {
		log.Fatal(err)
	}
	log.Println("File download request completed!")
	return nil
}
