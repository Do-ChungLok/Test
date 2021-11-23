#include <stdio.h>


int main(){
    int input_number, index=0, num; // input_number 입력값, index는 대각선 위치, num은 몇번째 분수(값)
    int sum=0;
    scanf("%d", &input_number);   // 사용자 입력값 받기

    while(1)    // 몇번째 행(대각선)인지 찾음
    {
        index++;
        sum = index * (index + 1)/2;
        if(input_number <= sum)
            break;
    }
    
    num = input_number - (index - 1) * index / 2;    // 그 행(대각선)에서 몇 번째 값인지 찾음

    if ( index % 2 == 0 )  // 짝수번째 대각선은 위에서 아래
    {
        printf("%d/%d", num, index - num +1);
    }

    else   // 홀수번째 대각선은 아래에서 위부터
        printf("%d/%d", index - num +1, num);

	return 0; 
}
