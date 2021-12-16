#include<stdio.h>

#define ARRAY_SIZE_MAX 101
#define SUM_COINS_MAX 10001
#define MAX(x, y) x > y ? x : y

using namespace std;

int app_num;     // 앱의 개수
int need_memory;    // 필요한 메모리
int app_memory_arr[ARRAY_SIZE_MAX];    // 현재 앱의 메모리 저장할 배열
int deactivate_cost_arr[ARRAY_SIZE_MAX];    // 앱을 비활성화 했을 경우 비용을 저장할 배열
int dp[SUM_COINS_MAX];    // 점화식 판단

void solution()
{
   
    for (int i = 1; i <= app_num; i++){
        for (int j = SUM_COINS_MAX; j >= 0; j--){
            if (j < deactivate_cost_arr[i]){
                break;
            }
            dp[j] = MAX(dp[j], dp[j - deactivate_cost_arr[i]] + app_memory_arr[i]);
        }    // dp[j] : 비용이 j 일때 가능한 최대 메모리 
    }        // dp[j - deactivate_cost_arr[i]] : i 번째 비용을 제외한 최대 메모리
             // app_memory_arr[i] : i 번째 메모리
                        
    for (int i = 0; i <= SUM_COINS_MAX; i++){
        if (dp[i] >= need_memory){    // dp 배열을 탐색하면서 확보한 메모리가 필요한 메모리보다 많다면 
            printf("%d", i);    // 출력
            break;
        }
    }                        

}

int main()
{
	scanf("%d %d", &app_num, &need_memory);    // 앱의 개수, 필요한 메모리 입력
    
	for (int i = 1; i <= app_num; i++)
	{
		scanf("%d ", &app_memory_arr[i]);    // 현재 앱의 메모리 입력
	}

	for (int i = 1; i <= app_num; i++)
	{
		scanf("%d ", &deactivate_cost_arr[i]);    // 비활성화 시 비용 입력
	}
    
    solution();    // 함수 호출

    return 0;

}
