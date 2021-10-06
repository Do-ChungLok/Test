#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
int main(void) { 
	int shmid, i; 
	char *shmaddr, *shmaddr2; 
	// 키를 IPC_PRIVATE로 지정해 공유 메모리를 20바이트 크기로 생성. 
	shmid = shmget(IPC_PRIVATE, 20, IPC_CREAT|0644); 
	if(shmid == -1) { 
		perror("shmget"); 
		exit(1); 
	} 
// fork 함수로 자식 프로세스를 생성 
	switch(fork()) { 
	
	case -1: 
		perror("fork"); 
		exit(1); 
		break; 
		
	case 0: // 자식 프로세스 수행영역 
		shmaddr = (char *)shmat(shmid, (char *)NULL, 0); // 공유 메모리 연결 
		printf("Child Process =====\n"); 
		
		for(i=0; i<10; i++) // 공유메모리에 'a'~'j'가지 문자 10개 기록 
			shmaddr[i] = 'a' + i; 
		shmdt((char *)shmaddr); // 공유 메모리 해제 
		exit(0); 
		break; 
		
	default: // 부모 프로세스 수행영역 
		wait(0); // 자식 프로세스가 종료하기를 기다린다. 
		shmaddr2 = (char *)shmat(shmid, (char *)NULL, 0); // 공유메모리 연결 
		printf("Parent Process =====\n"); 
		
		for(i=0; i<10; i++) // 공유 메모리의 내용을 읽어서 출력 
			printf("%c ", shmaddr2[i]); 
		printf("\n"); 
		// * sleep을 사용하는 이유 
		// ipcs 명령으로 공유 메모리의 상태를 확인하기 위해서. 물론 메시지 큐에서처럼 system 함수
		// 를 사용할 수도 있음. 다음처럼 공유 메모리가 생겼다가 프로세스가 종료된 후에는 삭제되는 			// 것을 알수 있음. 
		sleep(5); 
		
		shmdt((char *)shmaddr2); // 공유 메모리 해제 
		
		shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL); // shmctl 함수로 공유 메모리 제거 
		break; 
	} 
	
	return 0; 
}


