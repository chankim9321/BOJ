#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int status;
	
	pid_t pid;
	
	if((pid = fork()) < 0){
		perror("fork error");
		exit(1);
	}
	else if(pid == 0){ // child
		// mymv
		char* arg[2];
		arg[0] = argv[1];
		arg[1] = NULL;
		if(execv(argv[1], arg) < 0){
			perror("execvp child p");
			exit(1);
		}
	}
	else{
		wait(&status);
		// myfile
		char* arg[2];
		arg[0] = argv[2];
		arg[1] = NULL;
		if(execv(argv[2], arg) < 0){
			perror("execvp parent p");
		}
	}

	return 0;

}
