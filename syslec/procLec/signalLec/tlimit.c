#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int timer;
int pid;
int isEnd = 0;

void sigAlrmHandler(int signo){
	printf("Signal Handler Signal Number: %d\n", signo);
	if(!isEnd){
		kill(pid, SIGINT); // 자식 죽임
	}
	return;
}
void sigChildHandler(int signo){
	kill(getppid(), SIGALRM); // 부모 깨움
}
void playing(){
	for(int i=1; i<=10; i++){
		printf("playing %d seconds.\n", i);
		sleep(1);
	}
}
int main(int argc, char* argv[]){
	timer = atoi(argv[1]);
	printf("timer = %d\n", timer);
	signal(SIGALRM, sigAlrmHandler);	
	if((pid = fork()) == 0){
		if(execl(argv[2], (char*)NULL) == -1){
			perror("execlp");
		}
		isEnd = 1;
	}
	else{
		alarm(timer);
		pause();
	}
	return 0;
}
