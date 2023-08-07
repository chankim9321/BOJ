package databases

import (
	"log"
	"sync"

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

func GetMongoConnection() (*mongo.Client, error) {
	clientOnce.Do(func() {
		clientConfig.ApplyURI("mongodb://127.0.0.1:27017").SetMaxPoolSize(maxPoolSize)
		client, err = mongo.Connect(ctx, &clientConfig)
		if err != nil {
			log.Fatal("Failed to connect to MongoDB:", err)
		}
		err = client.Ping(ctx, nil)
		if err != nil {
			log.Fatal("Failed to ping MongoDB:", err)
		}
		log.Println("Connected to MongoDB! Addr : " + "127.0.0.1:27017")
	})
	return client, nil
}
