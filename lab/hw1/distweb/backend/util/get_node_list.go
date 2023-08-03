package util

import (
	"encoding/json"
	"log"
	"os"
)

type NodeRPCAddress struct {
	Addr []string `json:"node"`
}

func GetRPCAddressList() []string {
	data, err := os.ReadFile("./util/node_list.json")
	if err != nil {
		log.Fatal(err)
	}
	var mapping NodeRPCAddress
	err = json.Unmarshal(data, &mapping)
	if err != nil {
		log.Fatal(err)
	}
	return mapping.Addr
}
