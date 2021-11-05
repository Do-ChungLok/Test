#include <iostream> 
#include <sys/wait.h> // 'wait()' 때문에 사용한 라이브러리 
#include <unistd.h>   // 'execl()' 때문에 사용한 라이브러리

using namespace std; 

void start_osd()
{
	execl("/home/do/Test/ABinder/osd/osd","./A",(char*)NULL);
}

void start_ioman()
{
	execl("/home/do/Test/ABinder/ioman/ioman","./A",(char*)NULL);
}

void start_processes()
{   
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
		 exit(1);
}



int main() {
	start_processes();
}



