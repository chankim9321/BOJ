#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char* argv[]){
	int pd1, pd2, n;
	int status;
	char inmsg[80];
	char msg[80];
	char* filename1 = argv[1]; // 서버에서 입력한 채팅
	char* filename2 = argv[2]; // 내가 입력할 채팅

	printf("============= Client Side ============\n");
	int pid;
	switch(pid = fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0: // child (chat)
			if((pd2 = open(filename2, O_WRONLY)) == -1){
				perror("open");
				exit(1);
			}
			while(1){
				fgets(msg, 80, stdin);
				printf("To Server: %s", msg);
				n = write(pd2, msg, strlen(msg)+1);
				if(n == -1){
					perror("write");
					exit(1);
				}
				if(strcmp(msg, "quit\n") == 0){
					break;
				}
			}
			close(pd2);
			break;
		default: // parent (Listener);
			if((pd1 = open(filename1, O_RDONLY, 0666)) == -1){
				perror("open");
				exit(1);
			}
			while(1){
				n = read(pd1, inmsg, 80); // automatically wait
				if(strcmp(inmsg, "quit\n") == 0){
					break;
				}
				write(1, "From Server: ", 14);
				write(1, inmsg, n);
			}
			close(pd1);
			break;	
	}
	waitpid(pid, &status, 0);
	return 0;
}
