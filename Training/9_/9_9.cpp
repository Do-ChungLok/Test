#include <stdio.h>
int main()
{
    long x,y,z;
 
    while(1){
        scanf("%ld %ld %ld", &x, &y, &z);
        
        if(x==0 && y==0 && z==0)    // 0 0 0 입력하면 바로 종료(탈출)
        	break;
        x*=x;    
        y*=y;
        z*=z;

    	if(x==y + z || y==x + z || z==x + y)
    	{
        	printf("right\n");
    	}
    
    	else
    	{
        	printf("wrong\n");
    	}

    }
    
}
