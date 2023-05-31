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
	key_t key = ftok("keyfile", 1);
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

	num = (char*)memory_segment;

	while(1){
		if(num[0] == '1'){
			// 서버가 종료를 요청했을 때	
			if(strcmp((char*)&num[2], "exit\n") == 0){
				printf("Server Chatting Closed!");
				strcpy(&num[0], "0"); // 종료상황인지를 전달
				break;
			}
			else{
				printf("Received From Server: %s", (char*)&num[2]);
				printf("Client >> ");
				fgets(buf, 1000, stdin);
				strcpy(&num[2], buf);
				strcpy(&num[0], "0");
			}
		}
	}
	return 0;
}
