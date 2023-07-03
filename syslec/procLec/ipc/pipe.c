#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fd[2];
	int pid;
	char buf[257];
	int len, status;

	if(pipe(fd) == -1){
		perror("pipe");
		exit(1);
	}
	switch(pid = fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			close(fd[1]);
			write(1, "child process: ", 16);
			len = read(fd[0], buf, 256);
			write(1, buf, len);
			close(fd[0]);
			break;
		default:
			close(fd[0]);
			buf[0] = '\0';
			write(fd[1], "Test message from parents\n", 26);
			close(fd[1]);
			waitpid(pid, &status, 0);
			break;
	}
	return 0;
}
