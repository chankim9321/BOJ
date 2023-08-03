package main

import (
	nodes "backend/nodes"
	"log"
)

const ip = "127.0.0.1:"
const gRPCport = "9003"
const webPort = "5003"

func main() {
	go nodes.StartWebServer(ip, webPort, gRPCport)
	go nodes.StartGRPCServer(ip, gRPCport)
	go nodes.StartDBServer(ip, gRPCport)
	log.Printf("Node_3 initialized!")
	select {}
}
