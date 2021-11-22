#include <stdio.h>
int main(){
    int input;
    int count[42]={};
    int result = 0;
    
    for(int i=0; i<10; i++){
        scanf("%d\n",&input);
        count[input % 42]++; // 입력한 값을 42로 나누고 나머지를 배열에 저장
    }
    
    
    for(int i=0; i<42; i++){
       if(count[i] != 0)	// count[i]의 값이 없다면(0이라면) 셀 필요 없으니까 0이 아니라면 배열의 값이 존재 즉 result ++
       	result++;
    }
    
    printf("%d",result);
    
    
    return 0;
    
}


