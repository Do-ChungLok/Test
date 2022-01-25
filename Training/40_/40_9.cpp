#include <stdio.h>
#include <deque>

#define ARRAY_SIZE_MAX 100003

using namespace std;
typedef long long ll;

ll psum[ARRAY_SIZE_MAX];    // 1 ~ i 번째 합
ll arr[ARRAY_SIZE_MAX];     // 데이터 저장
ll dp[ARRAY_SIZE_MAX];      // i 까지의 최대 합
deque <int> dq;
int total_cow_num;    // 소의 총 수
int min_cow_num;    // 최소 소의 수

ll C(int i)
{
    return dp[i - 1] - psum[i];
}

int main()
{
    scanf("%d %d", &total_cow_num, &min_cow_num);    // 소의 총 수, 최소 수 입력

    for (int i = 1 ; i <= total_cow_num; i++) {
        scanf("%lld", &arr[i]);    // 데이터 입력
    }
    
    for (int i = 1 ; i <= total_cow_num; i++) {
        psum[i] = psum[i - 1] + arr[i];
    }
    
    for (int i = 1; i <= total_cow_num; i++) {
        while (!dq.empty() && dq.front() < i - min_cow_num) {
            dq.pop_front();    // 맨앞 원소 제거
        }
        
        while (!dq.empty() && C(dq.back()) <= C(i)) {
            dq.pop_back();    // 맨뒤 원소 제거
        }
        
        dq.push_back(i);
        dp[i] = psum[i] + C(dq.front());
        
        if (i <= min_cow_num) {    // 최소 수 보다 작은 경우
            dp[i] = max(dp[i], psum[i]);
        }
    }
    
    printf("%lld", dp[total_cow_num]);    // 출력
    
    return 0;
}
