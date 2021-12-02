#include <stdio.h>

#define INPUT_ROW_SIZE_MAX 501
#define INPUT_COL_SIZE_MAX 501

int input_arr[INPUT_ROW_SIZE_MAX][INPUT_COL_SIZE_MAX];

int Max(int num1, int num2)
{
    if (num1 > num2)
        return num1; 
    else
        return num2;
}

void Triangle_func(int N)
{
    int i,j;
    int max = -99999999;
    
    for (i = 1; i <= N; i++){
        for (j = 1; j <= i; j++){
            if (j == 1){         // 제일 왼쪽 원소
                input_arr[i][j] += input_arr[i-1][j];
            }
            
            else if (i == j){    // 제일 오른쪽 원소
                input_arr[i][j] += input_arr[i-1][j-1];
            }
            
            else{                // 자기 자신의 대각선 왼쪽 위, 오른쪽 위 에서 큰 값 + 자기 자신 값
                input_arr[i][j] = Max(input_arr[i-1][j], input_arr[i-1][j-1]) + input_arr[i][j];
            }
            
            if (input_arr[i][j] > max)
                max = input_arr[i][j];
        }  
    }
    printf("%d", max);
    
}

int main()
{
    int i,j;
    int N;    // 삼각형의 수  
    scanf("%d", &N);    // 삼각형의 수 입력
    
    for (i = 1; i <= N; i++){
        for (j = 1; j <= i; j++){    
            scanf("%d", &input_arr[i][j]);
        }
    }
    
    Triangle_func(N);
    

    return 0;
    
}
