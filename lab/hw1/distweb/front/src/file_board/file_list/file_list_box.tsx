import React, { useEffect, useState } from "react";
import styles from "./file_list_box.module.css";
import axios from "axios";
import FileUpload from "../file_upload/file_upload";
import nodeAddress from "./nodeAddr.json";

interface NodeProps {
  nodeID: number;
  reRender: () => void;
}
const FileListBox: React.FC<NodeProps> = (props) => {
  interface FileItem {
    id: string;
    name: string;
    size: number;
  }
  const [capacity, setCapacity] = useState(0);
  const [files, setFiles] = useState<FileItem[]>([]);
  const [errOccured, setErrOccured] = useState<Error | null>(null);
  const currentUrl = window.location.href; // 현재 웹서버의 주소
  const maxCapacity = 200; // 저장소 최대 용량
  const downloadFile = async (fileId: string, filename: string) => {
    try {
      // 파일 ID를 백엔드로 전송
      const nodeAddr: { [key: number]: string } = nodeAddress;
      const otherNodeAddr: string = nodeAddr[props.nodeID];
      fetch(
        `/download?fileId=${fileId}&nodeAddr=${otherNodeAddr}&fileName=${filename}`,
        { method: "GET" }
      ).then((response) => {
        if (!response.ok) {
          console.log("faild to download!");
          return;
        } else {
          // 백엔드에서 생성된 파일 다운로드 URL 받아오기
          response.blob().then((blob) => {
            const downloadURL = URL.createObjectURL(blob);
            // 파일 다운로드
            const link = document.createElement("a");
            link.href = downloadURL;
            link.download = filename;
            link.click();
          });
        }
      });
    } catch (error) {
      console.error("Error downloading file:", error);
    }
  };
  useEffect(() => {
    const nodeAddr: { [key: number]: string } = nodeAddress;
    const otherNodeAddr: string = nodeAddr[props.nodeID];
    const fetchData = async () => {
      try {
        // 데이터를 요청하여 응답 받기
        console.log(currentUrl);
        console.log(otherNodeAddr);
        const response = await axios.get(currentUrl + "/files", {
          params: {
            node: otherNodeAddr,
          },
        });
        // 응답 데이터를 상태에 업데이트
        setFiles(response.data);
        console.log(response.data);
        let nodeCapacity: number = 0;
        response.data.map((file: FileItem) => {
          nodeCapacity += file.size;
        });
        setCapacity(nodeCapacity);
      } catch (error: any) {
        if (error.code !== undefined) {
          setErrOccured(Error());
        }
        setCapacity(0);
        setFiles([]);
      }
    };
    fetchData();
  }, []);
  return (
    <>
      <div>
        {/* 150을 넘기면 빨간색으로 경고 색으로 */}
        {capacity > 150 ? (
          <div className={styles.capacityFull}>
            <p>
              Capacity: {capacity.toFixed(2)} MB / {maxCapacity} MB
            </p>
          </div>
        ) : (
          <div className={styles.capacityFree}>
            <p>
              Capacity: {capacity.toFixed(2)} MB / {maxCapacity} MB
            </p>
          </div>
        )}
        <div className={styles.fileTableContainer}>
          <table className={styles.fileTable}>
            <thead>
              <tr>
                <th>파일명</th>
                <th>파일 Object ID</th>
                <th>파일 크기</th>
              </tr>
            </thead>
            <tbody>
              {errOccured !== null ? (
                <h2 className={styles.disconnectionError}>
                  해당 노드와 연결이 끊겼습니다.
                </h2>
              ) : (
                files.map((file) => (
                  <tr key={file.id} className={styles.tableRow}>
                    <td
                      className={styles.tableCellName}
                      onClick={() => downloadFile(file.id, file.name)}
                    >
                      {file.name}
                    </td>
                    <td className={styles.tableCell}>{file.id}</td>
                    <td className={styles.tableCell}>{file.size}MB</td>
                  </tr>
                ))
              )}
            </tbody>
          </table>
        </div>
      </div>
      <FileUpload
        nodeID={props.nodeID}
        capacity={maxCapacity - capacity}
        reRender={props.reRender}
      />
    </>
  );
};
export default FileListBox;
