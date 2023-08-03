package main

import (
	nodes "backend/nodes"
	"log"
)

const (
	ip       = "127.0.0.1:" // localhost
	gRPCport = "9001"
	webPort  = "5001"
)

func main() {
	go nodes.StartWebServer(ip, webPort, gRPCport)
	go nodes.StartGRPCServer(ip, gRPCport)
	go nodes.StartDBServer(ip, gRPCport)
	log.Printf("Node_1 initialized!")
	select {}
}
