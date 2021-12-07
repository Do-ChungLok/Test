#include <stdio.h>

#define ARRAY_SIZE_MAX 1001
#define DIVISION_INTEGER 10007

//    ** 파스칼 삼각형 ** 
//           1  
//          1 1 
//        1  2  1         
//       1 3   3 1        ---> dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
//      1 4  6  4 1       ---> nCr = n-1Cr + n-1Cr-1 
//     1 5 10 10 5 1

int dp[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX] = {1, };

int pascal_triangle(int num1, int num2)    // 이항계수를 구하기 위해 사용되는 파스칼 삼각형 함수
{
    for (int i = 1; i <= num1; i++){
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++){
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % DIVISION_INTEGER;
        }
    }
    
    return dp[num1][num2];
}

int main()
{
    int input1, input2;       // 입력 숫자 1, 2
  
    scanf("%d %d", &input1, &input2);    // 숫자1, 2 입력  

    printf("%d", pascal_triangle(input1, input2));
    
}
