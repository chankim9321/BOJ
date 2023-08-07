#!/bin/bash

stop_server() {
  if [ -f "$1" ]; then
    pid=$(cat "$1")
    echo "서버 종료 중: $1"
    kill $pid
    rm "$1"
    echo "서버 종료 완료: $1"
  else
    echo "서버가 실행 중이지 않습니다: $1"
  fi
}

stop_server "n1.pid"
stop_server "n2.pid"
stop_server "n3.pid"
stop_server "n4.pid"
