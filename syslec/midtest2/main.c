#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	int status;
	
	pid_t pid;
	
	if((pid = fork()) < 0){
		perror("fork error");
		exit(1);
	}
	else if(pid == 0){ // child
		// mymv
		if(execlp(argv[1] argv[1], (char*)NULL) < 0){
			perror("execlp child p");
			exit(1);
		}
	}
	else{
		wait(&status);
		// myfile
		if(execlp(argv[2], argv[2], (char*)NULL) < 0){
			perror("execlp parent p");
		}
	}

	return 0;

}
