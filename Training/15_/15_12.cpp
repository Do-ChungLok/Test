#include <stdio.h>

#define ARRAY_SIZE_MAX 1001

int num_arr[ARRAY_SIZE_MAX];
int stacked_from_left[ARRAY_SIZE_MAX];
int stacked_from_right[ARRAY_SIZE_MAX];

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

    for (i = 1; i<= N; i++){
        scanf("%d", &num_arr[i]);
    }
    
    for (i = 1; i <= N; i++){    // 앞에서 뒤 (왼쪽 -> 오른쪽) 가장 긴 증가하는 부분 수열 찾기
        max = 0;    // 가장 큰 max 값 찾기 위해 0으로 초기화

        for (j = 0; j < i; j++){    
            if (num_arr[i] > num_arr[j]){        // 현재 값 (num_arr[i])보다 작은 이전값 (num_arr[j]) 중에서
                if (stacked_from_left[j] > max){ // 가장 큰 stacked_from_left[j] 값을 찾고 max에 저장
                    max = stacked_from_left[j];
                }
            }
        }
        
        stacked_from_left[i] = max + 1;    // i는 자신보다 작은 값만 찾았으니 +1 해줌  
    }    
       
    for (i = N; i > 0; i--){    // 뒤에서 앞 (오른쪽 -> 왼쪽) 가장 긴 증가하는 부분 수열 찾기
        max = 0;    // 가장 큰 max 값 찾기 위해 0으로 초기화        
        
        for (j = N; j > i; j--){    
            if (num_arr[i] > num_arr[j]){            // 현재 값 (num_arr[i])보다 작은 이전값 (num_arr[j]) 중에서
                if (stacked_from_right[j] > max){    // 가장 큰 stacked_from_right[j] 값을 찾고 max에 저장
                    max = stacked_from_right[j];
                }
            }
        }
        
        stacked_from_right[i] = max + 1;    // 현재 수열 길이 +1
    }    
    
    for (i = 1; i <= N; i++) { // 각배열을 앞에서 뒤로 탐색
        if (result < stacked_from_left[i] + stacked_from_right[i] - 1) { // 배열 값의 합산 - 1 이 가장큰 값 찾기
            result = stacked_from_left[i] + stacked_from_right[i] - 1;
        }
    }
    printf("%d", result);
}

