#include<stdio.h>

#define ARRAY_SIZE_MAX 101
#define SUM_COINS_MAX 10001

using namespace std;

int coin_kinds_num;     // 동전의 종류 개수
int sum_coins;    // 동전들의 합
int value_coin_arr[ARRAY_SIZE_MAX];    // 동전의 가치 저장할 배열
int dp[SUM_COINS_MAX];    // 점화식 판단'

void solution()
{
    dp[0] = 1;    // 초기값 설정
    for (int i = 1; i <= coin_kinds_num; i++){
        for (int j = value_coin_arr[i]; j <= sum_coins; j++){
            dp[j] = dp[j] + dp[j - value_coin_arr[i]];
        }    // dp[a] = b : 'a'원을 통해 만들 수 있는 경우의 수는 'b 가지'
    }
    // 1원을 만드는 경우의 수 : 1가지 -> 1원 X 1
    // 2원을 만드는 경우의 수 : 2가지 -> 1원 X 2, 2원
    // 3원을 만드는 경우의 수 : 3가지 -> 1원 X 3, 2원 + 1원, 3원
    // 4원을 만드는 경우의 수 : 4가지 -> 1원 X 4, 2원 X 2, 2원 + 1원  X 2, 4원
    
    printf("%d", dp[sum_coins]);    // 출력
}

int main()
{
	scanf("%d %d", &coin_kinds_num, &sum_coins);    // 동전의 종류 개수, 동전들의 합 입력
    
	for (int i = 1; i <= coin_kinds_num; i++)
	{
		scanf("%d", &value_coin_arr[i]);    // 동전의 가치 입력
	}

    solution();    // 함수 호출

    return 0;

}
