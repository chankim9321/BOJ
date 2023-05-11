#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int isCompleted = 0;
void sigUsr1Handler(int signo){
	raise(SIGALRM);
}
void sigAlrmHandler(int signo){
	if(isCompleted){
		printf("cooking completed\n");
		isCompleted = 0;
	}
	else return;	
}
void sigIntHandler(int signo){
	// doing nothing
	return;
}
void cooking(){
	printf("cooking\n");
	for(int i=10; i>=0; i--){
		printf("Remaining Time = %d\n", i);
		sleep(1);
	}
	isCompleted = 1;	
	raise(SIGALRM);
}
void setSigHandler(){
    signal(SIGALRM, sigAlrmHandler);
	signal(SIGINT, sigIntHandler);
	signal(SIGUSR1, sigUsr1Handler);
}
int main(int argc, char* argv[]){
	setSigHandler();	
	while(1){
		printf("Waiting..\n");
		sleep(30);
		// 요리시작
		cooking();
	}
}
