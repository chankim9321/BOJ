#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int shmid;
	char *num;
	key_t key= ftok("keyfile", 1);
	void *memory_segment=NULL;
	char buf[1000];

	if((shmid=shmget(key, 1024, IPC_CREAT|0666))==-1){
		printf("shmget failed\n");
		exit(0);
	}
	if((memory_segment=shmat(shmid,NULL,0))==(void*)-1){
		printf("shmat failed\n");
		exit(0);
	}
	printf("Shared memory 01 ID: %d\n",shmid);
	printf("Shared memory 01 attached address: %p\n\n",num);

	// init
	num = (char*)memory_segment;
	strcpy(&num[0], "0"); 
	int isFirstWritten = 0;
	// write on shm
	while(1){
		if(num[0] == '0'){
			if(isFirstWritten){
				printf("Received From Client: %s", (char*)&num[2]);
			}
			printf("Server >> ");
			fgets(buf, 1000, stdin);
			strcpy(&num[2], buf);
			strcpy(&num[0], "1");
			isFirstWritten = 1;
			if(strcmp((char*)&num[2], "exit\n") == 0){
				break;
			}
		}
	}
	while(num[0] == '1'); // 서버가 종료를 요청, 클라이언트가 받아들일때 까지 대기
	if(shmctl(shmid, IPC_RMID, 0) == -1){
		// 비정상적인 종료
		perror("shmctl IPC_RMID");
		exit(1);
	}
	return 0;
}
