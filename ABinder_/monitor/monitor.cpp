#include <iostream> 
#include <sys/wait.h> /* 'wait()' 사용 */
#include <unistd.h>   /* 'execl()' 사용 */

using namespace std; 

void start_osd()
{
	execl("/home/do/work/abinder/ABinder_/1110_ABinder/osd/osd","./A",(char*)NULL);
}

void start_ioman()
{
	execl("/home/do/work/abinder/ABinder_/1110_ABinder/ioman/ioman","./A",(char*)NULL);
}

void start_processes()
{   
	pid_t pid;
	pid=fork();
	
	if(pid>0){
		cout<< "[monitor] ID : " <<getpid() <<endl;
		wait(nullptr);
	 }
	
	else if(pid==0){
		pid=fork();
		
		if(pid>0){
			cout<< "[  osd  ] ID : " <<getpid() <<endl;
			start_osd();
		}
		
		else
			cout<< "[ ioman ] ID : " <<getpid() <<endl;
			start_ioman();
		}
	    
	else
		 cout<< "ERROR" <<endl;
		 exit(1);
}

int main() {
	start_processes();
}



