#include <iostream> 
#include <sys/wait.h> // 'wait()' 때문에 사용한 라이브러리 
#include <unistd.h>   // 'execl()' 때문에 사용한 라이브러리

#define EXIT_SUCCESS 0  
#define EXIT_FAILURE 1  

using namespace std; 

void start_osd()
{
	execl("/home/do/work/ABinder/osd/osd","./A",(char*)NULL);
}

void start_ioman()
{
	execl("/home/do/work/ABinder/ioman/ioman","./A",(char*)NULL);
}

int main() {
	
	pid_t pid;
	pid=fork();
		
		if(pid>0){
			cout <<"[monitor] ID:" <<getpid() <<endl;
			wait(nullptr);
		}

		else if(pid==0){
			pid=fork();

			if(pid>0){
				cout <<"[osd] ID:" <<getpid() <<endl;
				start_osd();
			}

			else
				cout <<"[ioman] ID:" <<getpid() <<endl;
				start_ioman();
		}

		else
			cout <<"ERROR" <<endl;
			exit(EXIT_FAILURE);

		return EXIT_SUCCESS;
}


