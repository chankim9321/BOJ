#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

int semInit(int semid, int semSize){
	if(semctl(semid, semSize, SETVAL, 1) == -1){
		perror("semctl in semInit");
		return -1;
	}
	return 1;
}
int semTryWait(int semid){
	struct sembuf semState;
	semState.sem_op = -1; // 세마포 사용
	semState.sem_num = 0; // 세마포 갯수 (0은 1개)
	semState.sem_flg = SEM_UNDO;
	if(semop(semid, &semState, 1) == -1){
		perror("semop in semTryWait");
		return -1;
	}
	return 0;
}
int semWait(int semid){
	struct sembuf semState;
	semState.sem_op = -1; // 세마포 사용
	semState.sem_num = 0; // 세마포 갯수 (0은 1개)
	semState.sem_flg = IPC_NOWAIT;
	if(semop(semid, &semState, 1) == -1){
		perror("semop in semWait");
		return -1;
	}
	return 0;
}
int semPost(int semid){
	struct sembuf semState;
	semState.sem_op = 1; // 세마포 반납
	semState.sem_num = 0;
	semState.sem_flg = SEM_UNDO;
	if(semop(semid, &semState, 1) == -1){
		perror("semop in semPost");
		return -1;
	}
	return 0;
}
void semRemove(int semid){
	if(semctl(semid, 0, IPC_RMID) == -1){
		perror("semctl : IPC_RMID");
		exit(1);
	}
}

