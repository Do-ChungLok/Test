#include <stdio.h>
#include <string.h>    // strcmp를 사용하기 위해
#include <deque>

#define INPUT_ARRAY_SIZE_MAX 10001

using namespace std;

deque<int> dq;

void push_front(int data)      // 입력한 데이터를 덱 앞에 넣는 연산
{
    dq.push_front(data);
}

void push_back(int data)       // 입력한 데이터를 덱 뒤에 넣는 연산
{
    dq.push_back(data);
}

int pop_front()                
{
    if (dq.empty()){            // 덱에 정수가 없으면 -1 출력
        return -1;
    }
    
    else{                       // 덱의 가장 앞에 있는 수를 빼고, 출력
        int num = dq.front();
        dq.pop_front();
        return num;
    }
}

int pop_back()                   // 덱에 정수가 없으면 -1 출력
{
    if (dq.empty()){
        return -1;
    }
    
    else{                        // 덱의 가장 뒤에 있는 수를 빼고, 출력
        int num = dq.back();
        dq.pop_back();
        return num;
    }
}

int size()              // 덱에 들어있는 정수 개수 반환
{
    return dq.size();
}

int empty()
{
    if (dq.empty()){    // 덱이 비어 있으면 1 출력
        return 1;
    }
    
    else{               // 덱이 비어있지 않으면 0 출력
        return 0;
    }
}

int front()
{
    if (dq.empty()){         // 덱에 정수가 없으면 -1 출력
        return -1;
    }
    
    else{             
        return dq.front();    // 덱의 가장 앞에 있는 정수 출력
    }
}

int back()
{
    if (dq.empty()){         // 덱에 정수가 없으면 -1 출력
        return -1;
    }
    
    else{               
        return dq.back();    // 덱의 가장 뒤에 있는 정수 출력
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
        
        if (strcmp(input_order, "push_front") == 0){    // strcmp(str1, sr2) : str1 == str2 인 경우 0 반환
            scanf("%d", &push_input_data);    // push 이후 정수 입력
            push_front(push_input_data);
        }

        else if (strcmp(input_order, "push_back") == 0){    // strcmp(str1, sr2) : str1 == str2 인 경우 0 반환
            scanf("%d", &push_input_data);    // back 이후 정수 입력
            push_back(push_input_data);
        }
        
        else if (strcmp(input_order, "pop_front") == 0){
            printf("%d\n", pop_front());
        }

        else if (strcmp(input_order, "pop_back") == 0){
            printf("%d\n", pop_back());
        }
        
        else if (strcmp(input_order, "size") == 0){
            printf("%d\n", size());
        }    
        
        else if (strcmp(input_order, "empty") == 0){
            printf("%d\n", empty());
        } 
        
        else if (strcmp(input_order, "front") == 0){    
            printf("%d\n", front());
        }   
        
        else if (strcmp(input_order, "back") == 0){     
            printf("%d\n", back());
        }         
        
    }
    
    return 0;
}
