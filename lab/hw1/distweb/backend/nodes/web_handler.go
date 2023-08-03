package backend

import (
	dispatch "backend/dispatch"
	pb "backend/protocol"
	util "backend/util"
	"encoding/json"
	"fmt"
	"io"
	"log"
	"math"
	"net/http"
	"os"
	"strconv"
	"strings"
)

type FileItem struct {
	ID   string  `json:"id"`
	Name string  `json:"name"`
	Size float64 `json:"size"`
}

func GetFilelistAPI(addr string) {
	http.HandleFunc("/files", func(w http.ResponseWriter, r *http.Request) {
		nodeAddr := r.URL.Query().Get("node")
		// 예시 데이터
		nodeAddrPort := strings.Split(nodeAddr, ":")[2] // http://localhost:xxxx 포트 번호 반환
		nodeRPCAddr := util.GetRPCAddressByWebPort(nodeAddrPort)

		var fileList *pb.FileInfoList
		fileList, err := dispatch.GetFileList(addr, nodeRPCAddr)
		var files []FileItem
		if err != nil { // 에러 발생시 빈 배열 전달
			log.Println("GetFilelistAPI 에러 발생 테스트:", err)
			w.Header().Set("Access-Control-Allow-Origin", "http://localhost:3000") // only Test server
			w.Header().Set("Content-Type", "application/json")
			json.NewEncoder(w).Encode(nil)
		}
		for _, row := range fileList.Filelist {
			size, err := strconv.ParseFloat(row.FileSize, 64)
			size = size / (1024 * 1024) // Default Size MB
			size = math.Round(size*100) / 100
			if err != nil {
				log.Fatal("failed to convert size: ", err)
			}
			file := FileItem{
				ID:   row.FileID,
				Name: row.FileName,
				Size: size,
			}
			files = append(files, file)
		}
		// 데이터를 JSON 형식으로 변환하여 응답으로 보냄
		w.Header().Set("Access-Control-Allow-Origin", "http://localhost:3000") // only Test server
		w.Header().Set("Content-Type", "application/json")
		json.NewEncoder(w).Encode(files)
	})
}
func UploadFileToSingleNodeAPI(addr string) {
	http.HandleFunc("/upload_single", func(w http.ResponseWriter, r *http.Request) {
		log.Println("UploadFileToSingleNodeAPI start running!")
		file, handler, err := r.FormFile("file")
		if err != nil {
			http.Error(w, "Failed to retrieve file", http.StatusInternalServerError)
			return
		}
		defer file.Close()

		port := strings.Split(addr, ":")[1]
		localStorage := util.GetStoragePathByMapping(port)
		// 파일 저장
		f, err := os.OpenFile(localStorage+handler.Filename, os.O_WRONLY|os.O_CREATE, 0666)
		if err != nil {
			http.Error(w, "Failed to open file", http.StatusInternalServerError)
			return
		}
		defer f.Close()
		io.Copy(f, file)

		metadata := dispatch.FileUploadRequestMetadata{
			RecvAddress:   addr,
			SenderAddress: addr,
			FilePath:      localStorage,
			FileName:      handler.Filename,
		}
		err = dispatch.UploadRequest(metadata)
		if err != nil {
			log.Fatal("upload request failed: ", err)
		}
		os.Remove(localStorage + handler.Filename)
		// 성공적인 응답 전송
		w.Header().Set("Content-Type", "application/json")
		fmt.Fprintf(w, `{"message": "File uploaded successfully"}`)
	})
}
func UploadFileToAllNodeAPI(addr string) {
	http.HandleFunc("/upload_all", func(w http.ResponseWriter, r *http.Request) {
		log.Println("UploadFileToAllNodeAPI start running!")
		file, handler, err := r.FormFile("file")
		if err != nil {
			http.Error(w, "Failed to retrieve file", http.StatusInternalServerError)
			return
		}
		defer file.Close()

		currentPort := strings.Split(addr, ":")[1]
		localStorage := util.GetStoragePathByMapping(currentPort)
		// 파일 저장
		f, err := os.OpenFile(localStorage+handler.Filename, os.O_WRONLY|os.O_CREATE, 0666)
		if err != nil {
			http.Error(w, "Failed to open file", http.StatusInternalServerError)
			return
		}
		defer f.Close()
		io.Copy(f, file)

		metadata := dispatch.FileUploadRequestMetadata{
			RecvAddress:   addr,
			SenderAddress: addr,
			FilePath:      localStorage,
			FileName:      handler.Filename,
		}
		nodeList := util.GetRPCAddressList()
		log.Println("nodeList (upload all): ", nodeList)
		for _, nodeAddr := range nodeList {
			nodePort := strings.Split(nodeAddr, ":")[1]
			if currentPort == nodePort {
				continue
			}
			metadata.RecvAddress = nodeAddr
			metadata.FilePath = util.GetStoragePathByMapping(nodePort)
			err = dispatch.UploadRequestToNode(metadata)
			if err != nil {
				log.Fatal("uploadRequestToNode err: ", err)
				os.Remove(localStorage + handler.Filename)
			}
		}
		// 로컬 db 저장 및 gRPC 전송
		metadata.FilePath = util.GetStoragePathByMapping(currentPort)
		metadata.RecvAddress = addr
		err = dispatch.UploadRequest(metadata) // current node upload
		if err != nil {
			log.Fatal("uploadRequest err: ", err)
			os.Remove(localStorage + handler.Filename)
		}
		os.Remove(localStorage + handler.Filename)
		// 성공적인 응답 전송
		w.Header().Set("Content-Type", "application/json")
		fmt.Fprintf(w, `{"message": "File uploaded To All Node successfully"}`)
	})
}
func DownloadFileAPI(addr string) {
	http.HandleFunc("/download", func(w http.ResponseWriter, r *http.Request) {
		log.Println("DonwloadFileAPI starts running!")
		if r.Method != http.MethodGet {
			http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
			return
		}
		nodeAddr := r.URL.Query().Get("nodeAddr") // 노드 주소
		fileID := r.URL.Query().Get("fileId")     // 파일 오브젝트 ID
		fileName := r.URL.Query().Get("fileName") // 파일 이름
		log.Println(nodeAddr, fileID, fileName)
		currentPort := strings.Split(addr, ":")[1]
		objectPort := strings.Split(nodeAddr, ":")[2]
		localStorage := util.GetStoragePathByMapping(currentPort) // 현재 노드의 로컬 스토리지
		objectRPCAddr := util.GetRPCAddressByWebPort(objectPort)
		objectPort = strings.Split(objectRPCAddr, ":")[1]
		metadata := dispatch.FileDownloadRequestMetadata{
			RecvAddress:   "",
			SenderAddress: addr,
			FileName:      fileName,
			FilePath:      localStorage,
			FileID:        fileID,
		}
		// 로컬에 저장 요청
		if currentPort != objectPort { // 현재 웹서버에 존재하지 않는 파일이라면
			metadata.RecvAddress = objectRPCAddr
			dispatch.DownloadRequestToNode(metadata)
		} else { // 현재 웹서버에 존재하는 파일이라면
			metadata.RecvAddress = addr
			dispatch.DownloadRequest(metadata)
			log.Println("Donwload completed in local")
		}
		http.ServeFile(w, r, localStorage+fileName)
		os.Remove(localStorage + fileName)
	})
}
