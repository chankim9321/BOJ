#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int pd1, pd2, n;
	int status;
	char msg[80];
	char inmsg[80];
	char* filename1 = argv[1]; 
	char* filename2 = argv[2];

	printf("========== Server Side ==========\n");

	if(mkfifo(filename1, 0666) == -1){
		perror("mkfifo");
		exit(1);
	}
	if(mkfifo(filename2, 0666) == -1){
		perror("mkfifo");
		exit(1);
	}
	int pid;
	switch(pid = fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0: // child
			if((pd1 = open(filename1, O_WRONLY)) == -1){
				perror("open");
				exit(1);
			}
			while(1){
				fgets(msg, 80, stdin);
				printf("To Client: %s", msg);
				n = write(pd1, msg, strlen(msg)+1);
				if(n == -1){
					perror("write");
					exit(1);
				}
				if(strcmp(msg, "quit\n") == 0){
					break;
				}
			}
			close(pd1);
			break;
		default: // parent
			if((pd2 = open(filename2, O_RDONLY)) == -1){
				perror("open");
				exit(1);
			}
			while(1){
				n = read(pd2, inmsg, 80); // automatically wait
				if(strcmp(inmsg, "quit\n") == 0){
					break;
				}
				write(1, "From Client: ", 14);
				write(1, inmsg, n);
			}
			close(pd2);
			break;
	}
	waitpid(pid, &status, 0);
	remove(filename1);
	remove(filename2);
	return 0;
}
