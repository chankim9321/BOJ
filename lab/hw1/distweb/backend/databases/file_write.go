package databases

import (
	"log"
	"os"

	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/gridfs"
	"go.mongodb.org/mongo-driver/mongo/options"
	"golang.org/x/net/context"
)

const chunkSize = 512 * 1024

func WriteFileOnMongoDB(conn *mongo.Client, filePath, filename string) error {
	log.Println("writeFileonMongo func start!")
	totalCapacity := 200 // 기본 capacity 200MB
	mb := 1024 * 1024
	openData, err := os.Open(filePath + filename)
	if err != nil {
		log.Fatal(err)
	}
	openDataStat, err := openData.Stat()
	if err != nil {
		log.Fatal(err)
	}
	data, err := os.ReadFile(filePath + filename)
	if err != nil {
		log.Fatal(err)
	}
	// init new bucket(file managing container) ChunkSize: 512 * 1024 (512KB)
	bucketOpts := options.GridFSBucket().SetChunkSizeBytes(chunkSize)
	_ = bucketOpts
	bucket, err := gridfs.NewBucket(conn.Database("files"))
	if err != nil {
		log.Fatal(err)
	}
	// get total fileSize
	log.Println("get total size start!")
	var result FileMetaData
	cursor, err := bucket.Find(bson.D{})
	if err != nil {
		log.Fatal(err)
	}
	defer cursor.Close(context.Background())

	var totalSize int64
	log.Println("cursur for loop start")
	for cursor.Next(context.Background()) {
		if err := cursor.Decode(&result); err != nil {
			log.Fatal(err)
		}
		totalSize += result.FileSize
	}
	log.Println("get total size end!")
	log.Println("total size: ", int(totalSize)/mb)
	log.Println("total Capacity,", totalCapacity)
	totalCapacity -= int(totalSize) / mb // 허용가능한 DB capacity
	// 파일 사이즈가 초과
	if totalCapacity < int(openDataStat.Size())/mb {
		log.Println("Write file to DB was failed due to file size exceeded")
		return nil
	}
	// 파일 쓰기 작업
	uploadStream, err := bucket.OpenUploadStream(filename)
	if err != nil {
		log.Fatal(err)
		os.Exit(1)
	}
	defer uploadStream.Close()

	fileSize, err := uploadStream.Write(data)
	if err != nil {
		log.Fatal(err)
		os.Exit(1)
	}
	log.Printf("Write file to DB was successful. File size: %d \n", fileSize)
	return nil
}
