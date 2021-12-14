#include <stdio.h>
#include <queue>    // 우선순위 큐 사용목적

using namespace std;    

priority_queue< int, vector<int>, greater<int> > pq;    // 최소 힙 우선순위 큐 선언

int main()
{
    int cal_num;         // 연산의 개수
    int input_number;    // 입력 정수
    
    scanf("%d", &cal_num);    // 연산의 개수 입력
    
    for (int i = 0; i < cal_num; i++){    // 연산의 개수 만큼 정수 입력
        scanf("%d", &input_number);
        
        if (input_number == 0){    // 만약에 입력한 정수가 '0'이라면
            if (pq.empty()){       // 입력한 정수가 '0'인데다가, 큐 안에 값이 없다면 '0' 출력
                printf("0\n");
            }
            
            else if (!pq.empty()){    // 입력한 정수가 '0'이지만 큐 안에 값이 있다면
                printf("%d\n", pq.top());    // 제일 우선순위에 있는 값 출력
                pq.pop();                    // 제일 우선순위에 있는 값 삭제
            }
        }
        
        else if (input_number != 0){    // 입력한 정수가 '0'이 아니라면
            pq.push(input_number);      // 입력한 정수 큐에 추가
        }   
    }

}
