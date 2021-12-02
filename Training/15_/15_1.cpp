#include <stdio.h>

#define SIZE_MAX 41

void fibonacci(int num) 
{
	// 변수명 규칙......   통일해서 쓰시길... snake_case  또는 CamelCase

    int Fibo_arr_0[SIZE_MAX]={1, 0};       // 0일때
    int Fibo_arr_1[SIZE_MAX]={0, 1, 0};    // 1일때
    
    for(int i = 2; i <= num; i++){
      Fibo_arr_0[i] = Fibo_arr_0[i - 1] + Fibo_arr_0[i - 2];  
      Fibo_arr_1[i] = Fibo_arr_1[i - 1] + Fibo_arr_1[i - 2];  
    }
    
    printf("%d %d\n", Fibo_arr_0[num], Fibo_arr_1[num]);
}

// 변수 대문자 사용 하지 마세요.  한글자 사용하지 마세요

int main()
{
    int T=0;            // 테스트 케이스 개수 변수    
    scanf("%d", &T);    // 테스트 케이스 개수 입력
    
    int input_num_arr[T];    // 테스트 케이스 개수 만큼의 배열 생성
    
    for (int i = 0; i<T; i++){     // 테스트 케이스 개수 만큼 배열에 input 입력
        scanf("%d", &input_num_arr[i]);     
    } 
    
	// 갯수 입력 SIZE_MAX 넘어가면 어떤일이??

    for (int i = 0; i<T; i++){     // 테스트 케이스 개수 만큼 함수 호출
        fibonacci(input_num_arr[i]);
    }
    return 0;
}

