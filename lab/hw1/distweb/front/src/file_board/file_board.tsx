import React, { useState } from "react";
import FileListBox from "./file_list/file_list_box";
import styles from "./file_board.module.css";

const FileBoard: React.FC = () => {
  const [node, setNode] = useState<string>("1"); // default node number 1
  const connectedLocation = window.location.href;
  const connectedNode = connectedLocation.split("5")[1].slice(0, -1);
  const [isUploaded, setIsUploaded] = useState<boolean>(false);
  const reRenderAfterUpload = () => {
    isUploaded === true ? setIsUploaded(false) : setIsUploaded(true);
  };
  const nodeButtonOnclick = (value: string) => {
    setNode(value);
  };
  return (
    <>
      <div className={styles.boardHead}>
        <h1>{connectedNode}번 노드</h1>
      </div>
      <div className={styles.boardHead}>
        <h2>{node}번 노드 저장소 File List</h2>
        <button onClick={() => nodeButtonOnclick("1")}>1번 노드</button>
        <button onClick={() => nodeButtonOnclick("2")}>2번 노드</button>
        <button onClick={() => nodeButtonOnclick("3")}>3번 노드</button>
        <button onClick={() => nodeButtonOnclick("4")}>4번 노드</button>
      </div>
      <FileListBox key={node} nodeID={node} reRender={reRenderAfterUpload} />
    </>
  );
};

export default FileBoard;
