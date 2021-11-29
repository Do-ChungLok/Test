#include <stdio.h>
#define MAX_SIZE 10001

int main(){
    int N,num;
    int num_arr_count[MAX_SIZE]={};    // 숫자 개수 저장하는 배열
    
    scanf("%d",&N);
    
    for(int i=0; i<N; i++){    // 입력한 숫자에 해당하는 배열에 저장 후 개수 카운트
    
        scanf("%d",&num);
        num_arr_count[num]++;
    }
    
    for(int i=1; i<MAX_SIZE;i++){
            for(int j=0; j<num_arr_count[i]; j++){    // 카운트한 숫자 출력
            	printf("%d\n",i);
            }
    }
    
    return 0;
}
