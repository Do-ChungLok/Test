#include <stdio.h>
#include <algorithm>
#include <climits>

#define ARRAY_SIZE_MAX 503

using namespace std;

int main() 
{
    int arr_num;    // 행렬 개수
    int size_arr1[ARRAY_SIZE_MAX];    // 행렬 A의 크기
    int size_arr2[ARRAY_SIZE_MAX];    // 행렬 B의 크기
    int dp[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // dp[x][y] : x ~ y 구간의 곱셈 연산 최소값
    
    scanf("%d", &arr_num);    // 행렬 개수 입력
    
    for (int i = 0 ; i < arr_num; i++){
        scanf("%d %d", &size_arr1[i], &size_arr2[i]);    // 행렬 크기들 입력
    }
    
    for (int i = 0; i < arr_num; i++){
        dp[i][i] = 0;    
    }
    
    for (int i = 1; i < arr_num; i++){    // 구간 범위의 크기
        for (int j = 0; j < arr_num - i; j++){    // 확인할 범위의 시작값
            int k = j + i;    // 확인할 범위의 끝값
            
            dp[j][k] = INT_MAX;
            
            for (int mid = j; mid < k; mid++){    // mid : 구해야하는 범위를 두 부분으로 나누는 기준점
                dp[j][k] = min(dp[j][k], dp[j][mid] + dp[mid + 1][k] +size_arr1[j] * size_arr1[mid + 1] * size_arr2[k]);
            }                                // size_arr1[j] : 구간 시작 부분의 행렬의 행 (N 역할)
        }                                    // size_arr1[mid + 1] : 구간을 둘로 나누는 기준점 행렬의 열 (M 역할)
    }                                        // size_arr2[k] : 구간 마지막 부분 행렬의 열 (K 역할)
    
    printf("%d", dp[0][arr_num - 1]);    // 출력 : 0 ~ 행렬 개수 만큼 곱했을 때 연산의 최소값

    return 0;
}
