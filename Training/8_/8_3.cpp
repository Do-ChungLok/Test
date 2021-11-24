#include <stdio.h>

int main(){
	int A,B,V;
	int day_high=0;    //n일 낮 기준 올라가는 높이 : n*A - (n-1)*B
	int n=0;
    
	scanf("%d %d %d", &A, &B, &V);
	
	while(1)
	{
	n++;
	day_high = n*A -(n-1)*B;
	
	if(day_high >= V)
		break;
	}
	
	printf("%d",n);

	return 0; 
}

/*
#include <stdio.h>
#include <math.h>

int main(){
	int A,B,V;
	int n=0;    // n*A - (n-1)*B >= V -> n으로 정리하면 n >= (V-B)/(A-B) 
    

	scanf("%d %d %d", &A, &B, &V);
	n = ceil((double)(V - B) / (A - B));    // ceil : 소숫점을 올려줌

    
	printf("%d",n);

	return 0; 
}
*/
