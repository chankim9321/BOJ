package main

import (
	nodes "backend/nodes"
	"log"
)

const (
	gRPCport = "9001"
	webPort  = "5001"
)

func main() {
	go nodes.StartWebServer("0.0.0.0:", webPort, gRPCport)
	go nodes.StartGRPCServer("0.0.0.0:", gRPCport)
	go nodes.StartDBServer("127.0.0.1:", gRPCport)
	log.Printf("Node initialized!")
	select {}
}
