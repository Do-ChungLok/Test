#include <stdio.h>
#include <queue>    // 우선순위 큐 사용목적
#include <algorithm>

using namespace std;    

// pair형으로 두개 원소 대입, 'greater' 사용하여 오름차 순으로, 먼저 'first' 비교하고, 같다면 'second' 비교
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;   

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
                printf("%d\n", pq.top().second);    // 절대값이 같다면 그냥 가장 작은수(second 값) 출력
                pq.pop();                    // 제일 우선순위에 있는 값 삭제
            }
        }
        
        else if (input_number != 0){    // 입력한 정수가 '0'이 아니라면
            pq.push(make_pair(abs(input_number), input_number));      // 입력한 정수 큐에 추가
        }   
    }
    return 0;
}
