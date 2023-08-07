package main

import (
	// "context"
	// "io"
	"log"
	// "os"

	nodes "backend/nodes"
)

const ip = "127.0.0.1:"
const gRPCport = "9002"
const webPort = "5002"

func main() {
	go nodes.StartWebServer(ip, webPort, gRPCport)
	go nodes.StartGRPCServer(ip, gRPCport)
	go nodes.StartDBServer(ip, gRPCport)
	log.Printf("Node_2 initialized!")

	select {}
}
