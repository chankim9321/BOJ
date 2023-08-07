package databases

import (
	"bytes"
	"fmt"
	"log"
	"os"
	"time"

	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo"

	"go.mongodb.org/mongo-driver/mongo/gridfs"

	// "go.mongodb.org/mongo-driver/mongo/options"
	"golang.org/x/net/context"
)

type FileMetaData struct {
	ID       primitive.ObjectID `bson:"_id"`
	Name     string             `bson:"filename"`
	FileSize int64              `bson:"length"`
}

func DownloadFileFromMongoDB(conn *mongo.Client, localStoragePath string, fileID string) error {
	db := conn.Database("files")
	fsFiles := db.Collection("fs.files") // file metadata collection
	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)

	var results FileMetaData
	objectID, err := primitive.ObjectIDFromHex(fileID)
	if err != nil {
		log.Fatal(err)
	}
	err = fsFiles.FindOne(ctx, bson.D{{"_id", objectID}}).Decode(&results)
	if err != nil {
		log.Fatal(err)
	}
	bucket, _ := gridfs.NewBucket(db)

	buffer := bytes.NewBuffer(nil)
	dStream, err := bucket.DownloadToStream(results.ID, buffer)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("File size to download: %v \n", dStream)
	// donwload to local

	err = os.WriteFile(localStoragePath+results.Name, buffer.Bytes(), 0600)
	if err != nil {
		log.Fatal(err)
	}
	return nil
}
