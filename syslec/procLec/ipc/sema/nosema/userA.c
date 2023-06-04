#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int shmid;
	void* shmaddr;
	char buf[100];
	key_t key = ftok("keyfile", 1);

	if((shmid = shmget(key, 1024, IPC_CREAT|0666)) == -1){
		perror("shmget");
		exit(1);
	}
    if((shmaddr = shmat(shmid, NULL, 0)) == (void*)-1){
		perror("shmat");
		exit(1);
	}
    for(int a=1; a<=10; a++) {
		// Start of Critical Section
        strcpy(shmaddr, "Keimyung");
        sleep(1);
        strcpy(buf, shmaddr);
		// End of Critical Section
        printf("A : %s\n", buf);
    }
	return 0;
}
