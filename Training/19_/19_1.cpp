#include <stdio.h>
#include <string.h>    // strcmp를 사용하기 위해

#define QUEUE_ARRAY_SIZE_MAX 2000000
#define INPUT_ARRAY_SIZE_MAX 10001

int queue[QUEUE_ARRAY_SIZE_MAX];    // 큐 배열 전연 변수로 선언
int front = 0;                       
int rear = -1;

void push(int data)      // 입력한 데이터를 큐에 넣는 연산
{
    queue[++rear] = data;
}

void pop()                // 큐에 정수가 없으면 -1 출력
{
    if (rear - front +1 == 0){
        printf("%d\n", -1);
    }
    
    else{                // 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력
        printf("%d\n", queue[front++]);
    }
}

void size()              // 큐에 들어있는 정수 개수 반환
{
    printf("%d\n", rear - front + 1);
}

void empty()
{
    if (rear - front +1 != 0){    // 큐가 비어있지 않으면 0 출력
        printf("%d\n", 0);
    }
    
    else{               // 큐가 비어 있으면 1 출력
        printf("%d\n", 1);
    }

}

int main()
{
    int order_num;    // 명령의 수
    char input_order[INPUT_ARRAY_SIZE_MAX];    // 입력할 명령 문자열
    int push_input_data;    // push 이후 입력할 숫자
    
    scanf("%d", &order_num);    // 명령의 수 입력
    
    for (int i = 0; i < order_num; i++){
        scanf("%s", input_order);    // 명령 입력
        
        if (strcmp(input_order, "push") == 0){    // strcmp(str1, sr2) : str1 == str2 인 경우 0 반환
            scanf("%d", &push_input_data);    // push 이후 정수 입력
            push(push_input_data);
        }
        
        else if (strcmp(input_order, "pop") == 0){
            pop();
        }
        
        else if (strcmp(input_order, "size") == 0){
            size();
        }    
        
        else if (strcmp(input_order, "empty") == 0){
            empty();
        } 
        
        else if (strcmp(input_order, "front") == 0){    // rear 초기값 : -1, front 초기값 : 0 이니까 
            if (rear - front +1 == 0){                  // -1 -0 +1 == 0 인경우 -> 즉 큐에 들어있는 정수가 없는 경우
                printf("%d\n",-1);
            }
            else{
                printf("%d\n", queue[front]);
            }
        }   
        
        else if (strcmp(input_order, "back") == 0){     // rear 초기값 : -1, front 초기값 : 0 이니까
            if (rear - front +1 == 0){                  // -1 -0 +1 == 0 인경우 -> 즉 큐에 들어있는 정수가 없는 경우
                printf("%d\n",-1);
            }
            else{
                printf("%d\n", queue[rear]);
            }
        }         
        
    }
    
    return 0;
}
