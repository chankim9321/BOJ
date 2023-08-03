package util

import (
	"encoding/json"
	"log"
	"os"
)

type PortStorageMapping struct {
	Ports map[string]string `json:"ports"`
}

func GetStoragePathByMapping(port string) string {
	data, err := os.ReadFile("./util/storage_by_ports.json")
	if err != nil {
		log.Fatal(err)
	}

	var mapping PortStorageMapping
	err = json.Unmarshal(data, &mapping)
	if err != nil {
		log.Fatal(err)
	}
	return mapping.Ports[port]
}
