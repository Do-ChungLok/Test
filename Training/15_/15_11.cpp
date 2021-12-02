#include <stdio.h>

#define ARRAY_SIZE_MAX 1001

int num_arr[ARRAY_SIZE_MAX];
int stacked_num[ARRAY_SIZE_MAX];

int Max(int num1, int num2)
{
    if (num1 > num2)
        return num1; 
    else
        return num2;
}

int main()
{
    int N;    // 수열A의 크기
    int max = 0, result = 0;
    int i, j;
    
    scanf("%d", &N);    // 수열 A의 크기 입력

    for (i = 1; i <= N; i++){
        max = 0;    // 최종 출력할 수열 길이 0으로 초기화
        scanf("%d", &num_arr[i]);
        
        for (j = 0; j < i; j++){    // j < i --> j가 i 까지 탐색하며 현재 i 보다 작은 값만 찾음
            if (num_arr[i] > num_arr[j]){
                if (stacked_num[j] > max){
                    max = stacked_num[j];
                }
            }
        }
        
        stacked_num[i] = max + 1;    // i는 자신보다 작은 값만 찾았으니 +1 해줌
        result = Max(result, stacked_num[i]);
    }    
    printf("%d", result);
}

