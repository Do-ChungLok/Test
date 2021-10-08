#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdio.h>

#define MAX_THREAD  5

int count = 0;

void *myThreadFunc(void *data);

struct sembuf mysem_open = {0, -1, SEM_UNDO};
struct sembuf mysem_close = {0, 1, SEM_UNDO};

union semun
{
	int val; 
	struct semid_ds *buf; 
	unsigned short *array; 
};

static int semid;

int main(int argc, char **argv)
{
    int thr_id;
    int status;
    int i;
    
    union semun s_union;
    
    pthread_t pt[MAX_THREAD];       //스레드 2개

    semid = semget(2345, 1, 0600|IPC_CREAT);

    if(semid == -1)
    {
        perror("semget error");
        return 1;
    }

    
    s_union.val = 1;

    
    //세마포어의 세부값 제어
    //SETVAL: 세마포어의 semval 값을 arg.val로 설정.
    
   
    if(semctl(semid, 0, SETVAL, s_union) == -1)
    {
        return 1;
    }

    
    for(i = 0; i < MAX_THREAD; i++)
    {
        //스레드 생성
        thr_id = pthread_create(&pt[i], NULL, myThreadFunc, (void *)&i);
        
        //성공할경우 쓰레드식별자인 thread에 쓰레드 식별번호를 저장하고, 0을 리턴. 
        //실패했을경우 0 이 아닌 에러코드 값을 리턴.
        
        if(thr_id < 0)
        {
            perror("Thread Create Error");
            return 1;
        }
        
        sleep(1);
    }
    
    
    for(i = 0; i < MAX_THREAD; i++)
    {
        //pthread_join 는 실별번호 th 로 시작된 쓰레드가 종료되는걸 기다린다.
        pthread_join(pt[i], NULL);
    }
}

void *myThreadFunc(void *data)
{
    int thread_num = *(int *)data;
    int lnum;
    printf("Thread Create : %d\n", thread_num);
    while(1)
    {

        //*잠금, 해제 세마포어 연산 수행               
   
        semop(semid, &mysem_open, 1);
        
        lnum = count;
       
        sleep(1);
        
        lnum = lnum+1;
        
        count = lnum;
        
        printf("[스레드%d번] count : %d\n", thread_num, count);
        
        semop(semid, &mysem_close, 1);
    }
}
