import React, { useState } from "react";
import styles from "./file_upload.module.css";
import nodeAddress from "../file_list/nodeAddr.json";
interface NodeProps {
  nodeID: string;
  capacity: number;
  reRender: () => void;
}
const FileUpload: React.FC<NodeProps> = (props) => {
  // const nodeAddr: { [key: number]: string } = nodeAddress;
  const [nodeID, setNodeID] = useState(props.nodeID);
  const [selectedFile, setSelectedFile] = useState<File | null>(null);
  const [fileName, setFileName] = useState<string>("");
  const [fileSize, setFileSize] = useState<number>(0);
  const handleFileChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    const file = event.target.files && event.target.files[0];
    if (file) {
      setSelectedFile(file);
      setFileName(file.name);
      setFileSize(file.size / (1024 * 1024));
      console.log(file.size / (1024 * 1024));
    } else {
      setFileName("");
      setFileSize(0);
    }
  };
  const capacityFullAlarm = () => {
    alert("파일의 용량이 저장소 용량을 초과합니다!");
  };
  const uploadSingleNode = () => {
    console.log("uploadSingleNode test (not selected)");
    if (selectedFile) {
      console.log("uploadSingleNode test");
      const formData = new FormData();
      formData.append("file", selectedFile);
      formData.append("node", props.nodeID);
      fetch("/upload_single", {
        method: "POST",
        body: formData,
      })
        .then((response) => response.json())
        .then((data) => {
          console.log("File uploaded to single successfully:", data);
        })
        .catch((error) => {
          console.error("Error uploading file:", error);
        });
      alert("파일이 현재 노드에 업로드 되었습니다!");
    }
  };
  const uploadAllNodes = () => {
    if (selectedFile) {
      const formData = new FormData();
      formData.append("file", selectedFile);
      fetch("/upload_all", {
        method: "POST",
        body: formData,
      })
        .then((response) => response.json())
        .then((data) => {
          console.log("File uploaded to all nodes successfully:", data);
        })
        .catch((error) => {
          console.error("Error uploading file:", error);
        });
      alert("파일이 모든 노드에 업로드 되었습니다!");
    }
  };
  return (
    <>
      <div>
        <label htmlFor="fileInput" className={styles.fileInputLabel}>
          파일 업로드
        </label>
        <input
          type="file"
          id="fileInput"
          onChange={handleFileChange}
          className={styles.fileInput}
        />
        {fileName && (
          <div className={styles.fileSelected}>선택된 파일: {fileName}</div>
        )}
        <button
          onClick={
            fileSize < props.capacity ? uploadAllNodes : capacityFullAlarm
          }
          className={
            fileSize < props.capacity
              ? styles.fileUploadButtonFree
              : styles.fileUploadButtonFull
          }
        >
          모든 노드에 저장
        </button>
        <button
          onClick={
            fileSize < props.capacity ? uploadSingleNode : capacityFullAlarm
          }
          className={
            fileSize < props.capacity
              ? styles.fileUploadButtonFree
              : styles.fileUploadButtonFull
          }
        >
          현재 노드에 저장
        </button>
      </div>
    </>
  );
};

export default FileUpload;
