#include <stdio.h>

#define INPUT_STACK_ARRAY_SIZE_MAX 100001

int stack[INPUT_STACK_ARRAY_SIZE_MAX];    // stack 배열 전연 변수로 선언
int count = 0;                            // stack 배열에 처음 시작할 때 아무 값도 없으니 '0' 초기화

void push(int data)    // push 연산
{
    stack[count] = data;
    count += 1;
}

void pop()             // pop 연산
{
        count--;
        stack[count] = 0;
}

int main()
{
    int input_num;                // 입력 정수의 수
    int sum = 0;                  // 남은 정수 합
    
    scanf("%d", &input_num);      // 입력할 정수의 수 입력
    
    int input_data[input_num];    // 입력할 정수 배열
    
    for (int i = 0; i < input_num; i++){
        scanf("%d", &input_data[i]);
        
        if (input_data[i] == 0){    // 정수 '0'을 입력하면 pop함수 실행
            pop();
        }
        
        else{                       // 정수 '0' 제외한 정수 입력하면 push함수 실행
            push(input_data[i]);
        }
    }
    
    for (int j = 0; j < count; j++){    // stack배열에 남은 정수들 합하여 출력
        sum += stack[j];
    }
    
    printf("%d\n", sum);
    
    return 0;
}
