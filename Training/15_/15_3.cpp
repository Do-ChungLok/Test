// n : 1 -> 1
// n : 2 -> 2
// n : 3 -> 3
// n : 4 -> 5
// n : 5 -> 8 ... ----> '피보나치' 수열

#include <stdio.h>
#define SIZE_MAX 1000000

int Fibo_arr[SIZE_MAX] = {};    // 배열 선언

void fibonacci(int input_num)
{
    Fibo_arr[1] = 1;
    Fibo_arr[2] = 2;
    
    for(int i = 3; i<= input_num; i++){
        Fibo_arr[i] = (Fibo_arr[i - 1] + Fibo_arr[i - 2]) %15746; // 문제 조건에서 2진 수열의 개수를 '15746'으로 나눈 나머지 출력
    }
}

int main()
{
    int N;    
    scanf("%d", &N);    // 자연수 입력 
    fibonacci(N);       // '피보나치 함수'에 N 대입
    
    printf("%d\n", Fibo_arr[N]);
    
    return 0;
}
