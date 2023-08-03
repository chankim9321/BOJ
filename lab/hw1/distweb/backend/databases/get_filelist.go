package databases

import (
	"context"
	"log"
	"strconv"
	"time"

	pb "backend/protocol"

	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo"
)

type FileDoc struct {
	FileID   primitive.ObjectID `bson:"_id"`
	FileSize int64              `bson:"length"`
	FileName string             `bson:"filename"`
}

func GetFileListFromMongoDB(conn *mongo.Client) (*pb.FileInfoList, error) {
	db := conn.Database("files")
	fsFiles := db.Collection("fs.files") // file metadata collection
	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)

	cursur, err := fsFiles.Find(ctx, bson.M{})
	if err != nil {
		log.Fatal("fsFiles.Find(): ", err)
	}
	var fileList pb.FileInfoList
	for cursur.Next(ctx) {
		var doc FileDoc
		if err := cursur.Decode(&doc); err != nil {
			log.Fatal(err)
		}
		fileInfo := &pb.FileInfoList_FileInfo{
			FileID:   doc.FileID.Hex(),
			FileName: doc.FileName,
			FileSize: strconv.Itoa(int(doc.FileSize)),
		}
		fileList.Filelist = append(fileList.Filelist, fileInfo)
	}
	return &fileList, nil
}
