package util

import (
	"encoding/json"
	"log"
	"os"
)

type RPCAddress struct {
	Addr map[string]string `json:"RPCaddr"`
}

func GetRPCAddressByWebPort(port string) string {
	data, err := os.ReadFile("./util/grpc_by_webport.json")
	if err != nil {
		log.Fatal(err)
	}
	var mapping RPCAddress
	err = json.Unmarshal(data, &mapping)
	if err != nil {
		log.Fatal(err)
	}
	return mapping.Addr[port]
}
