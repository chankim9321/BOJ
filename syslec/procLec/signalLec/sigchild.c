#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int pidList[5]; // 자식 ps list
int pidEnd[5]; // 프로세스가 끝났는지 확인하는 배열
int cnt = 0;
int pid;
int k = 0;

void sigChildHandler(int signo){
    int status, pid;
    if((pid = waitpid(pidList[k], &status, 0)) > 0){
        printf("child terminated : %d\n", pid);
		cnt++;
		pidEnd[k++] = 1;
    }
}
void sigAlrmHandler(int signo){
    return;
}
void setSignalHandler(){
    signal(SIGCHLD, sigChildHandler);
    signal(SIGALRM, sigAlrmHandler);
}
int main(int argc, char* argv[]){
    setSignalHandler(); // 시그널 핸들러 설정
    // 자식 프로세스 생성
    for(int i=0; i<5; i++){
		pidEnd[i] = 0;
        pid = fork();
        if(pid == 0) break;
        else pidList[i] = pid; // 부모프로세스는 자식들의 프로세스 번호를 저장
    }
    if(pid == 0){ // 자식 프로세스 실행 명령어 구역
        /*
            ...
            ...
        */
		pause();
    }
    else{
		int idx = 0;
		// 자식 프로세스의 수행시간이 전부 랜덤이고, 순차적으로 끝내야 한다면
		// 부모 프로세스는 자식프로세스 수행이 끝났을 때, 즉 pause() 실행될 때 까지
		// 알람 시그널을 계속 호출한다.
		// if문을 통해 프로세스 종료의 여부를 확인후 idx값을 증가시켜 순차적으로 확인, 종료한다.
        while(cnt < 5){
			kill(pidList[idx], SIGALRM);
			if(pidEnd[idx]) idx++;
		}
        printf("부모 종료\n");
    }
    return 0;
}
