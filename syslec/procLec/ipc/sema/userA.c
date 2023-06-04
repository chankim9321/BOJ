#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "semalib.h"

int main(int argc, char* argv[]){
	int status;
	int shmid;
	int semid;
	int pid;
	void* shmaddr;
	char buf[100];
	key_t semKey = 12345;
	key_t key = ftok("keyfile", 1);
	char* filename = argv[1];

	if((semid = semget(semKey, 1, IPC_CREAT|0666)) == -1){
		perror("semget");
	}
	if((shmid = shmget(key, 1024, IPC_CREAT|0666)) == -1){
		perror("shmget");
		exit(1);
	}
    if((shmaddr = shmat(shmid, NULL, 0)) == (void*)-1){
		perror("shmat");
		exit(1);
	}
	if(semInit(semid, 0) == -1){
		exit(1);
	}

	switch(pid = fork()){
		case 0:
			if(execv(filename, NULL) == -1){
				perror("execv");
				exit(1);
			}
			break;
		default:
			for(int a=1; a<=10; a++) {
				if(semTryWait(semid) == -1){
					exit(1);
				}
				// Start of Critical Section
				strcpy(shmaddr, "Keimyung");
				sleep(1);
				strcpy(buf, shmaddr);
				// End of Critical Section
				if(semPost(semid) == -1){
					exit(1);
				}
				printf("A : %s\n", buf);
			}
			wait(NULL);
			if(shmctl(shmid, IPC_RMID, NULL) == -1){
				perror("shmctl : IPC_RMID, check IPCS");
			}
			semRemove(semid);
    }
	return 0;
}
