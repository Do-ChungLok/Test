#include <errno.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/sem.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
// 세마포어 공용체를 정의
union semun { 
	int val; 
	struct semid_ds *buf; 
	unsigned short *array; 
}; 
int initsem(key_t semkey) { 
	union semun s_union; 
	int status = 0, semid; 
	
	// 인자로 받은 키를 지정해 세마포어 식별자를 생성
	// 리턴값이 -1이고, errno 값이 EEXIST면 이미 존재하는 
	// 세마포어 식별자라는 의미이므로 기존 식별자를 읽어옴
	
	semid = semget(semkey, 1, IPC_CREAT | IPC_EXCL | 0600); 
	if(semid == -1) { 
		if (errno == EEXIST) 
		semid = semget(semkey, 1, 0); 
	} else { 
		// semctl 함수를 사용해 세마포어 값을 1로 초기화 
		s_union.val = 1; 
		status = semctl(semid, 0, SETVAL, s_union); 
	} 
		if(semid == -1 || status == -1) { 
		perror("initsem"); 
		return (-1); 
	} 
	return semid; 
} 
int semlock(int semid){ 
	// semlock 함수는 sem_op 값을 -1로 설정해 공유 자원을 얻고 잠금 기능을 수행
	// 세마포어 값의 초깃값을 1로 설정했으므로, 처음 semlock 함수를 실행하는 프로세스는 
	// 세마포어 값에서 1을 빼면 0이 되어 잠금 기능을 수행
	struct sembuf buf; 
	
	buf.sem_num = 0; 
	buf.sem_op = -1; 
	
	// sem_flg를 UNDO로 설정해 문제가 발생하면 동작 취소 가능
	buf.sem_flg = SEM_UNDO; 
	if(semop(semid, &buf, 1) == -1) { 
		perror("semlock failed"); 
		exit(1); 
	} 
	return 0; 
} 

int semunlock(int semid) { 
	// semunlock 함수는 sem_op 값을 1로 설정해 사용 중인 공유 자원의 잠금 기능을 	
	// 해제하고 되돌려주려 한다. 처음 semunlock 함수를 호출하면 세마포어 값이 0이므로 
	// 여기에 1을 더하면 세마포어 값이 양수가 되어 잠금을 해제 	
	struct sembuf buf; 
	
	buf.sem_num = 0; 
	buf.sem_op = 1; 
	
	// sem_flg를 UNDO로 설정해 문제가 발생하면 동작 취소 가능 
	buf.sem_flg = SEM_UNDO; 
	if(semop(semid, &buf, 1) == -1) { 
		perror("semunlock failed"); 
		exit(1); 
	} 
	return 0; 
}

// semhandle 함수는 세마포어를 생성해 잠금을 수행하고 
// 작업한 후 다시 잠금 해제
void semhandle() { 
	int semid; 
	pid_t pid = getpid(); 
	
	if((semid = initsem(1)) < 0) 
		exit(1); 
		
	semlock(semid); 
	// /// 여기서는 간단한 출력문이나 실제로는 중요한 처리 부분이 오게 됨
	printf("Lock : Process %d\n", (int)pid); 
	printf("** Lock Mode : Critical Section\n"); 
	sleep(1); 
	printf("Unlock : Process %d\n", (int)pid); 
	
	semunlock(semid); 
	
	exit(0); 
} 
	
	// main 함수에서는 fork 함수를 세 번 호출해 자식 프로세스 세 개를 생성, 
	// 각 자식 프로세스는 semhandle 함수를 실행. 
	// 즉, 자식 프로세스가 모두 semhandle 함수를 실행하게 된다. 
int main(void) { 
	int a; 
	for(a = 0; a < 5; a++) 
		if(fork() == 0) semhandle(); 
		
	return 0; 
}

