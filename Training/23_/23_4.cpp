#include<stdio.h>
#include<algorithm>

#define ARRAY_SIZE_MAX 2001

using namespace std;

int dp[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];
int sequence_arr[ARRAY_SIZE_MAX];    // 칠판에 적은 숫자를 저장할 배열
int sequence_size, question_num;    // 수열의 크기, 질문의 개수
int start_point, end_point;    // 시작, 끝 지점

int main()
{
	scanf("%d", &sequence_size);    // 수열의 크기 입력
    
	for (int i = 1; i <= sequence_size; i++)
	{
		scanf("%d", &sequence_arr[i]);
		dp[i][i] = 1; // 한자리수는 무조건 팰린드롬
        
		if (i != 1 && sequence_arr[i - 1] == sequence_arr[i]) // "1 1", "2 2", "4 4"와 같이 두자리가 같은 경우도 팰린드롬
			dp[i - 1][i] = 1;
	}
		
	for (int i = 2; i <= sequence_size - 1; i++)	// 구간 범위의 크기
	{
		for (int j = 1; i + j <= sequence_size ; j++)	// 확인할 범위의 시작값
		{
            int k = j + i;	// 확인할 범위의 끝값
            
			if (sequence_arr[j] == sequence_arr[k] && dp[j + 1][i + j - 1] == 1)
				dp[j][k] = 1;    // 조건 만족시 팰린드롬
		}
	}

	scanf("%d", &question_num);    // 질문 개수 입력

	for (int i = 0; i < question_num; i++)
	{
		scanf("%d %d", &start_point, &end_point);    // 시작, 끝 지점 입력

		printf("%d\n", dp[start_point][end_point]);    // 출력
	}

}
