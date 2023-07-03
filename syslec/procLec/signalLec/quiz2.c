#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int isCompleted = 0;
char command = ' '; 
int pid;
int iter = 1;
void dbf(){while(getchar() != '\n');}
void cooking(){
	printf("cooking\n");
	for(int i=5; i>=0; i--){
		printf("Remaining Time = %d\n", i);
		sleep(1);
	}
	isCompleted = 1;	
	raise(SIGALRM); // 요리가 다됬음을 알림 
}
void sigUsr1Handler(int signo){
	printf("order received\n");
	raise(SIGALRM);
}
void sigAlrmHandler(int signo){
	if(isCompleted){
		printf("cooking completed\n");
		isCompleted = 0;
	}
	if(iter){
		iter = 0;
	}
}
void sigIntHandler(int signo){
	if(command == 'n'){
		printf("parent: kill CHild Process\n");
		kill(pid, SIGINT);
	}
	else if(command == ' '){
		exit(1);
	}
}
void setSigHandler(){
    signal(SIGALRM, sigAlrmHandler);
	signal(SIGINT, sigIntHandler);
	signal(SIGUSR1, sigUsr1Handler);
}
int main(int argc, char* argv[]){ 
	pid = fork();
	setSigHandler();
	while(1){
		if(pid == 0){ // 자식
			pause(); // 부모가 sigusr1을 날릴때 까지 대기
			command = 'c';
			cooking();
			command = ' ';
			kill(getppid(), SIGALRM); // 부모 깨우기
		}
		else{ // 부모
			printf("do you want to order? (y,n) ");
			command = getc(stdin);
			dbf();
			if(command == 'y'){ // 주문을 할 때
				iter = 1;
				printf("order transmitted\n");
				kill(pid,SIGUSR1); // 자식 프로세스에게 명령
				while(iter);
			}
			else{ // 주문이 끝나면 자식 종료
				raise(SIGINT);
				break;
			}
		}
	}
	int status;
	wait(&status);
	return 0;
}
