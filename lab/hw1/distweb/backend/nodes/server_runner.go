package backend

import (
	"log"
	"net"
	"net/http"

	db "backend/databases"
	pb "backend/protocol"
	ss "backend/protocol/server_side"

	grpc "google.golang.org/grpc"
)

func StartWebServer(ip string, port string, grpcPort string) {
	log.Println("WEB SERVER ONLINE :" + ip + port)
	// webserver init
	http.Handle("/", http.FileServer(http.Dir("../front/build")))

	// Send file list
	log.Println(ip + port)
	GetFilelistAPI(ip + grpcPort)
	UploadFileToSingleNodeAPI(ip + grpcPort)
	UploadFileToAllNodeAPI(ip + grpcPort)
	DownloadFileAPI(ip + grpcPort)
	http.ListenAndServe(ip+port, nil)
}

func StartGRPCServer(ip string, port string) {
	lis, err := net.Listen("tcp", ip+port)
	if err != nil {
		log.Fatalf("Failed to listen: %v", err)
	}

	server := grpc.NewServer(grpc.MaxRecvMsgSize(1024*1024*10), grpc.MaxSendMsgSize(1024*1024*10))
	fileTransferService := &ss.FileTransferServer{}
	pb.RegisterFileTransferServiceServer(server, fileTransferService)

	if err := server.Serve(lis); err != nil {
		log.Fatalf("Failed to serve: %v", err)
	}
}
func StartDBServer(ip string, port string) {
	db.GetMongoConnection(ip + port)
}
