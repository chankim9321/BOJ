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
)

type FileItem struct {
	ID   string  `json:"id"`
	Name string  `json:"name"`
	Size float64 `json:"size"`
}

func GetFilelistAPI(addr string) {
	http.HandleFunc("/files", func(w http.ResponseWriter, r *http.Request) {

		// 목적지 서버는 Docker 컨테이너의 DNS 주소이다
		// ex) node1:9001 => dns resolved 0.0.0.0:9001
		// 도커에서 사용할 땐 밑에 2줄을 주석 처리 해제
		nodeNumber := r.URL.Query().Get("node") // string type
		nodeRPCAddr := "node" + nodeNumber + ":9001"
		// nodeRPCAddr := "0.0.0.0:9001"

		var fileList *pb.FileInfoList
		fileList, err := dispatch.GetFileList(addr, nodeRPCAddr)
		var files []FileItem
		if err != nil { // 에러 발생시 빈 배열 전달
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

		// 9001은 노드 grpc 서버 고정포트
		// ex) node1:9001 => DNS resolved localhost:9001
		// 도커에서 사용할 땐 밑에 2줄을 주석 처리 해제
		nodeNumber := r.FormValue("node") // 목적지 노드
		nodeRPCAddr := "node" + nodeNumber + ":9001"
		// nodeRPCAddr := "0.0.0.0:9001"
		localStorage := util.GetStoragePathByMapping("9001")
		// 파일 저장
		f, err := os.OpenFile(localStorage+handler.Filename, os.O_WRONLY|os.O_CREATE, 0666)
		if err != nil {
			http.Error(w, "Failed to open file", http.StatusInternalServerError)
			return
		}
		defer f.Close()
		io.Copy(f, file)

		metadata := dispatch.FileUploadRequestMetadata{
			RecvAddress:   nodeRPCAddr, // 목적지 RPC 서버
			SenderAddress: addr,        // 호출자 주소
			FilePath:      localStorage,
			FileName:      handler.Filename,
		}
		err = dispatch.UploadRequestToNode(metadata)
		if err != nil {
			log.Fatal("upload request failed: ", err)
		}

		os.Remove(localStorage + handler.Filename) // 로컬 임시 파일 삭제
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

		// currentPort := strings.Split(addr, ":")[1] // 현재노드의 포트
		localStorage := util.GetStoragePathByMapping("9001")
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

		// node 목록 수정필요
		// p2p로 노드를 디스커버리 했을 때 따로 로컬에 해당 노드에 대한 주소를 핸들링해서 요청이 요구된다
		// nodeList := util.GetRPCAddressList()
		// log.Println("nodeList (upload all): ", nodeList)

		// for _, nodeAddr := range nodeList {
		// 	nodePort := strings.Split(nodeAddr, ":")[1]
		// 	if currentPort == nodePort {
		// 		continue
		// 	}
		// 	metadata.RecvAddress = nodeAddr
		// 	metadata.FilePath = util.GetStoragePathByMapping("9001")
		// 	err = dispatch.UploadRequestToNode(metadata)
		// 	if err != nil {
		// 		log.Fatal("uploadRequestToNode err: ", err)
		// 		os.Remove(localStorage + handler.Filename)
		// 	}
		// }

		// 해당 노드 로컬에 저장하므로 RPC 통신이 불필요
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
		nodeAddr := r.URL.Query().Get("nodeAddr") // 노드 주소 type: string
		fileID := r.URL.Query().Get("fileId")     // 파일 오브젝트 ID
		fileName := r.URL.Query().Get("fileName") // 파일 이름

		localStorage := util.GetStoragePathByMapping("9001") // 현재 노드의 로컬 스토리지
		objectRPCAddr := "node" + nodeAddr + ":9001"         // 목적지 노드의 RPC 서버주소 (DNS로 설정되며 목적지 노드에서 resolve 됨)

		// 파일 다운로드 요청을 위한 메타데이터
		metadata := dispatch.FileDownloadRequestMetadata{
			RecvAddress:   "",
			SenderAddress: addr,
			FileName:      fileName,
			FilePath:      localStorage,
			FileID:        fileID,
		}
		// RPC 파일 요청
		metadata.RecvAddress = objectRPCAddr
		dispatch.DownloadRequestToNode(metadata)

		// 웹서버에 파일 전송
		http.ServeFile(w, r, localStorage+fileName)
		// 로컬 파일 삭제
		os.Remove(localStorage + fileName)
	})
}
