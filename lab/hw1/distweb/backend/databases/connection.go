package databases

import (
	"log"
	"strings"
	"sync"

	util "backend/util"

	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
	"golang.org/x/net/context"
)

var (
	ctx          context.Context
	client       *mongo.Client
	clientOnce   sync.Once
	err          error
	clientConfig options.ClientOptions
	maxPoolSize  uint64 = 3
)

func GetMongoConnection(address string) (*mongo.Client, error) {
	clientOnce.Do(func() {
		address = util.GetDBaddressByMapping(strings.Split(address, ":")[1])
		clientConfig.ApplyURI(address).SetMaxPoolSize(maxPoolSize)
		client, err = mongo.Connect(ctx, &clientConfig)
		if err != nil {
			log.Fatal("Failed to connect to MongoDB:", err)
		}
		err = client.Ping(ctx, nil)
		if err != nil {
			log.Fatal("Failed to ping MongoDB:", err)
		}
		log.Println("Connected to MongoDB! Addr : " + address)
	})
	return client, nil
}
