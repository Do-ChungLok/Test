#include <stdio.h>
#include <string.h>    // strcmp를 사용하기 위해

#define INPUT_STACK_ARRAY_SIZE_MAX 100001
#define INPUT_ARRAY_SIZE_MAX 10001

int stack[INPUT_STACK_ARRAY_SIZE_MAX];    // stack 배열 전연 변수로 선언
int count = 0;                            // stack 배열에 처음 시작할 때 아무 값도 없으니 '0' 초기화

void push_X(int data)    // 정수 X를 스택에 넣는 연산
{
    stack[count] = data;
    count += 1;
}

int pop()                // 스택에서 가장 위에 있는 정수를 빼고, 그 수를 반환
{
    if (count != 0){
        count--;
        return stack[count];
    }
    
    else{                // 스택에 정수가 없으면 -1 반환
        return -1;
    }
}

int top()               // 스택의 가장 위에 있는 정수 반환
{
    if (count != 0){
        return stack[count - 1];
    }
    
    else{               // 스택에 정수가 없으면 -1 반환
        return -1;
    }              
}

int size()              // 스택에 들어있는 정수 개수 반환
{
    return count;
}

int empty()
{
    if (count == 0){    // 스택이 비어 있으면 1 반환
        return 1;
    }
    
    else{               // 스택이 비어있지 않으면 0 반환
        return 0;
    }

}

int main()
{
    int order_num;    // 명령의 수
    char input_order[INPUT_ARRAY_SIZE_MAX];    // 입력할 명령 문자열
    int push_input_data;    // push 이후 입력할 숫자
    
    scanf("%d", &order_num);    // 명령의 수 입력
    
    for (int i = 0; i < order_num; i++){
        scanf("%s", input_order);
        
        if (strcmp(input_order, "push") == 0){    // strcmp(str1, sr2) : str1 == str2 인 경우 0 반환
            scanf("%d", &push_input_data);    // push 이후 정수 입력
            push_X(push_input_data);
        }
        
        else if (strcmp(input_order, "pop") == 0){
            printf("%d\n", pop());
        }
        
        else if (strcmp(input_order, "top") == 0){
            printf("%d\n", top());
        }    
        
        else if (strcmp(input_order, "size") == 0){
            printf("%d\n", size());
        } 
        
        else if (strcmp(input_order, "empty") == 0){
            printf("%d\n", empty());
        }        
    }
    
    return 0;
}
