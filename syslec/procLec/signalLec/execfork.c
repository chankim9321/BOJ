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
int n = 0;
void sigChildHandler(int signo){ // 부모입장에서 받음
    int status, pid;
	if((pid = waitpid(pidList[k], &status, WNOHANG)) > 0){
		printf("child terminated : %d, status = %d, %d\n", pid, WIFEXITED(status), WIFSIGNALED(status));
		cnt++;
		pidEnd[k++] = 1;
	}
}
void sigAlrmHandler(int signo){
    return;
}
void sigUsr1Handler(int signo){
	n++;	
}
void setSignalHandler(){
	signal(SIGUSR1, sigUsr1Handler);
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
		printf("pid = %d, 작업 수행중\n", getpid());
		for(long long i=0; i<5000000000; i++); // 대략 5초
        /*
            ...
            ...
        */
		printf("pid = %d, 작업 종료. 대기중\n", getpid());
		kill(getppid(), SIGUSR1);	
		pause();
    }
    else{
		int player = fork();
		if(player == 0){
			if(execl(argv[1], (char*)NULL) == -1){ // 노래재생
				perror("execl");
				exit(1);
			}
		}
		else{
			int idx = 0;
			int status;
			while(cnt < 5){
				if(n == 5){
					kill(pidList[idx], SIGALRM);
					if(pidEnd[idx]) idx++;
				}
			}
			kill(player, SIGINT); // 노래 종료
			printf("부모 종료\n");
		}
    }
    return 0;
}
