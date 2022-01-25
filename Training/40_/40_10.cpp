#include <stdio.h>
#include <deque>

#define ARRAY_SIZE_MAX 100002

using namespace std;
typedef long long ll;

struct sequence {
    ll data; // 원소값
    int position;  // 원소가 위치한 인덱스
};

deque <sequence> dq;

ll bridge_num;  // 징검다리 수
ll min_diff;    // 두 다리 최소 거리
ll arr[ARRAY_SIZE_MAX];
ll dp[ARRAY_SIZE_MAX];
 
int main() 
{
    scanf("%lld %lld", &bridge_num, &min_diff);    // 징검다리 수, 두 다리 최소 거리 입력
    ll result = -1e9;    // 최소값 초기화 설정
    //deque <sequence> dq;
    
    for (int i = 1; i <= bridge_num; i++) {
  
        scanf("%lld", &arr[i]);    // 데이터 입력
        
        // i-d<=idx 유지 <-> i-d>idx인 동안 제거
        while (!dq.empty() && dq.front().position < i - min_diff) {
            dq.pop_front();    // 맨앞 원소 제거
        }

        if (dq.empty()) {    // 비어있다면 dp 갱신
            dp[i] = arr[i];    // 데이터 입력
        }
        
        else {
            dp[i] = max(0LL, dq.front().data) + arr[i];
        }
        
        result = max(result, dp[i]);     // 최대 갱신
        
        // dp[idx] > dp[i] 유지 <-> dp[idx] <= dp[i]인 동안 제거
        while (!dq.empty() && dq.back().data <= dp[i]) {
            dq.pop_back();    // 맨뒤 원소 제거
        }
   
        dq.push_back({dp[i], i});    // 덱에 넣기 
    }
    printf("%lld\n", result);    // 출력
   
    return 0;
}

