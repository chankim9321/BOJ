package util

import (
	"encoding/json"
	"log"
	"os"
)

type PortDBaddressMapping struct {
	DbPorts map[string]string
}

func GetDBaddressByMapping(port string) string {
	data, err := os.ReadFile("./util/DBaddress_by_ports.json")
	if err != nil {
		log.Fatal(err)
	}

	var mapping PortDBaddressMapping
	err = json.Unmarshal(data, &mapping)
	if err != nil {
		log.Fatal(err)
	}
	return mapping.DbPorts[port]
}
