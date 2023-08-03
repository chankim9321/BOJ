import React, { useState } from "react";
import FileListBox from "./file_list/file_list_box";
import styles from "./file_board.module.css";

const FileBoard: React.FC = () => {
  const [node, setNode] = useState<number>(1); // default node number 1

  const nodeButtonOnclick = (value: number) => {
    console.log(value);
    setNode(value);
  };
  return (
    <>
      <div className={styles.boardHead}>
        <h2>{node}번 노드 저장소</h2>
        <button onClick={() => nodeButtonOnclick(1)}>1번 노드</button>
        <button onClick={() => nodeButtonOnclick(2)}>2번 노드</button>
        <button onClick={() => nodeButtonOnclick(3)}>3번 노드</button>
        <button onClick={() => nodeButtonOnclick(4)}>4번 노드</button>
      </div>
      <FileListBox key={node} nodeID={node} />
    </>
  );
};

export default FileBoard;
