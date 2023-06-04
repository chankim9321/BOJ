#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "semalib.h"

int main(){
	int semid;
	int shmid;
	void* shmaddr;
	char buf[100];
	key_t semKey = 12345;
	key_t key = ftok("keyfile", 1);

	if((semid = semget(semKey, 0, IPC_CREAT|0666)) == -1){
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
    for(int a=1; a<=10; a++) {
		if(semTryWait(semid) == -1){
			exit(1);
		}
		// Start of Critical Section
        strcpy(shmaddr, "University");
        sleep(1);
        strcpy(buf, shmaddr);
		// End of Critical Section
		if(semPost(semid) == -1){
			exit(1);
		}
        printf("B : %s\n", buf);
    }
	return 0;
}
