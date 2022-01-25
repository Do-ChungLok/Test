#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct sequence {
    int data; // 원소값
    int position;  // 원소가 위치한 인덱스
};

int main() 
{
    int num;    // 수 개수
    int length;    // 수열 길이
    
    scanf("%d %d", &num, &length);    // 수 개수, 수열 길이 입력
    
    vector <int> arr(num);    // 수 저장할 벡터
    for (int i = 0; i < num; ++i) {
       
        scanf("%d", &arr[i]);    // 수 입력
    }

    deque <sequence> dq;
    for (int i = 0; i < num; ++i) {
        
        // 나갈 차례 된 수는 삭제
        if (!dq.empty() && dq.front().position == i - length) 
            dq.pop_front();	// 맨 앞 원소 제거
        
        // arr[i]보다 커서 최소값 될 수 없는 기존 deque 안의 원소들은 삭제
        while (!dq.empty() && dq.back().data > arr[i]) 
            dq.pop_back();	// 맨 뒤 원소 제거
        
        dq.push_back({ arr[i], i });     // arr[i] 추가
        printf("%d ", dq.front().data);    // deque 맨앞 원소 출력
    }
    
    return 0;
}
