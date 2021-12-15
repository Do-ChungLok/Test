#include <stdio.h>
#include <algorithm>
#include <climits>	// INT_MAX 

#define ARRAY_SIZE_MAX 503

using namespace std;

int main() 
{
    int case_num;    // 테스트 케이스 수
    int page_num;    // 소설을 구성하는 장의 수
    int dp[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // 최소값 저장할 배열
    int file[ARRAY_SIZE_MAX];    // 데이터를 입력받을 배열      
    int sum[ARRAY_SIZE_MAX];    // 부분합 저장할 배열
    
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    
    while(case_num--) {
        
        scanf("%d", &page_num);    // 장의 수 입력
        for (int i = 1; i <= page_num; i++) {
            
            scanf("%d", &file[i]);    // 데이터 입력
            sum[i] = sum[i - 1] + file[i];
        }
        
        for (int i = 1; i < page_num; i++){
            for (int j = 1; j <= page_num - i; j++){    // 확인할 범위의 시작값
                int k = j + i;    // 확인할 범위의 끝값
                
                dp[j][k] = INT_MAX;    // 최소값 비교를 위해 INF
                
                for (int mid = j; mid < k; mid++){    // mid : 구해야하는 범위를 두 부분으로 나누는 기준점
                    dp[j][k] = min(dp[j][k], dp[j][mid] + dp[mid + 1][k] + sum[k] - sum[j - 1]);
                }    // dp[j][k] : j ~ k 번째 파일 합치는데 필요한 최소 비용, sum[k] : 1 ~ k 번째 파일까지 크기의 합
            }
        }

        printf("%d\n", dp[1][page_num]);    // 출력
    }
    return 0;
}
