#include <stdio.h>
#include <queue>    // 우선순위 큐 사용목적

using namespace std;    

int main()
{
    priority_queue< int, vector<int>, less<int> > max_heap;       // 최대 힙 우선순위 큐 선언
    priority_queue< int, vector<int>, greater<int> > min_heap;    // 최소 힙 우선순위 큐 선언
    
    int integer_num;     // 외치는 정수의 개수
    int input_number;    // 외치는 정수
    int max_heap_top;
    int min_heap_top;
    
    scanf("%d", &integer_num);    // 외치는 정수의 개수 입력
    
    for (int i = 0; i < integer_num; i++){   
        scanf("%d", &input_number);    // 외치는 정수 입력
        
        if (max_heap.size() == 0){    // 처음 큐에 값이 비어있을 때 최대힙에 넣기
            max_heap.push(input_number);
        }
        
        else {    // 큐에 값이 비어있지 않을때
            
            if (max_heap.size() > min_heap.size()){    // 최대 힙의 크기 > 최소 힙의 크기 : 최소 힙에 값을 넣기
                min_heap.push(input_number);
            }      
        
            else if (max_heap.size() == min_heap.size()) {    // 최대 힙의 크기 == 최소 힙의 크기 : 최대 힙에 값을 넣기
                max_heap.push(input_number);
            }
        
            if (max_heap.top() > min_heap.top()){    // 최대 힙의 top 값이 최소 힙의 top 값보다 크다면 값을 교환
                max_heap_top = max_heap.top();
                min_heap_top = min_heap.top();
            
                max_heap.pop();
                min_heap.pop();
            
                max_heap.push(min_heap_top);
                min_heap.push(max_heap_top);
            }
        }
        
        printf("%d\n", max_heap.top());
    }
    
    return 0;
}
