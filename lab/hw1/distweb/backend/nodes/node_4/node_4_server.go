package main

import (
	nodes "backend/nodes"
	"log"
)

const ip = "127.0.0.1:"
const gRPCport = "9004"
const webPort = "5004"

func main() {
	go nodes.StartWebServer(ip, webPort, gRPCport)
	go nodes.StartGRPCServer(ip, gRPCport)
	go nodes.StartDBServer(ip, gRPCport)
	log.Printf("Node_4 initialized!")

	select {}
}
