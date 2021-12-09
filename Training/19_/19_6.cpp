#include <stdio.h>
#include <deque>

using namespace std;

#define ARRAY_SIZE_MAX 51

int main()
{
    int queue_size; // 큐의 크기
    int want_num;   // 뽑아내려고 하는 수의 개수
    int location[ARRAY_SIZE_MAX];   // 뽑아내려고 하는 수의 위치를 저장할 배열
    int sum = 0;    // count들의 합
    
    deque<int> dq;
    
    scanf("%d %d", &queue_size, &want_num);    // 큐의 크기, 뽑아내려고 하는 수의 개수 입력
    
    for (int i = 1; i <= queue_size; i++){
        dq.push_back(i);
    }
      
    for (int i = 0; i < want_num; i++){        // 뽑아내려는 수 입력
        scanf("%d", &location[i]);
    }
     
    for (int i = 0; i < want_num; i++){
        int count1 = 0, count2 = 0;
        
        deque<int> dq1(dq);
        deque<int> dq2(dq);
        
        while(dq1.front() != location[i]){    // case3 : 오른쪽 방향으로 진행
            dq1.push_back(dq1.front());       // 제일 왼쪽 값을 제일 오른쪽 값 뒤로 이동    
            dq1.pop_front();                  // 제일 왼쪽 값 pop
            count1++;                         // 오른쪽 방향 진행했다는 count1 증가
        }
        
        while(dq2.back() != location[i]){     // case2 : 왼쪽 방향으로 진행
            dq2.push_front(dq2.back());       // 제일 오른쪽 값을 제일 왼쪽 값 앞으로 이동
            dq2.pop_back();                   // 제일 오른쪽 값 pop
            count2++;                         // 왼쪽 방향 진행했다는 count2 증가
        }
        
        if (count1 > count2){                 // count1이 count2 보다 크다는 말은 case2 (왼쪽) 방향이 더 빠르다는 말과 같음
            sum += count2 + 1;                // 시작점이 제일 앞쪽에 진행하므로 +1
            dq2.pop_back();
            dq = dq2;
        }
        
        else{                                 // count2이 count1 보다 크다는 말은 case3 (오른쪽) 방향이 더 빠르다는 말과 같음
            sum += count1;                   
            dq1.pop_front();
            dq = dq1;
        }
    }
    
    printf("%d\n",sum);
    
    return 0;
}
        
   
    
  

