#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <stdarg.h>
#define MAX_SIZE 10

void mysystem(int cnt, ...){ // 가변인자 설정
	char* argv[MAX_SIZE]; 
	va_list argptr;
	va_start(argptr, cnt);
	// 가변인자를 문자열 배열에다 담는다
	for(int i=0; i<cnt; i++){
		argv[i] = va_arg(argptr, char*);
	}
	argv[cnt] = NULL;
	va_end(argptr);
	printf("command [%s]\n", argv[0]);
	if(execvp(argv[0], argv) < 0){
		perror("execvp error");
	}
}
int main(int argc, char* argv[]){
	pid_t pid;
	int status;
	if((pid = fork()) < 0){
		perror("fork error");
		exit(1);
	}
	else if(pid == 0){ // child
		printf("----------> child proc start. my parent pid = %d\n",getppid());	
		int pid = fork();
		int status;
		if(pid == 0){
			mysystem(1, "who");
		}
		else{
			wait(&status);
			pid = fork();
			if(pid == 0){
				mysystem(2, "ls", "-al");
			}
			else{
				wait(&status);
				mysystem(1, "date");
			}
		}
	}
	else{ // parent
		wait(&status); // wait child proc
		printf("----------> i'm parent proc. my pid is %d\n", getpid());
	}
	return 0;
}
