#include <stdio.h>

#define MOD_NUM 1000000000
#define ROW_SIZE_MAX 101
#define COL_SIZE_MAX 10

int main(void){
    int N;
    int stair_num_arr[ROW_SIZE_MAX][COL_SIZE_MAX] = {};
    int sum = 0;
    
    scanf("%d", &N);
    for (int i = 0; i < 10; i++)
        stair_num_arr[1][i] = 1;
    
    for (int i = 2; i <= N; i++){
        for (int j = 0; j < 10; j++){    
            if (j == 0)    // '0'은 +1을 한 '1'만 허용됨
                stair_num_arr[i][0] = stair_num_arr[i - 1][1] % MOD_NUM;
            
            else if (j == 9)    // '9'는 -1을 한 '8'만 허용됨
                stair_num_arr[i][9] = stair_num_arr[i - 1][8] % MOD_NUM;
            
            else     //  j 자릿수 i 수에 대해서 j-1 자릿수의 i-1과 i+1을 더한 수가 i 수에 대한 값이 되는것
                stair_num_arr[i][j] = (stair_num_arr[i - 1][j - 1] + stair_num_arr[i - 1][j + 1]) % MOD_NUM;
        }            // stair_num_arr[i][j] = stair_num_arr[i - 1][j - 1] + stair_num_arr[i - 1][j + 1] 
                     // => 길이가 i 일 때, 마지막 수가 j일 경우의 계단 수
    }
    
    for (int i = 1; i < 10; i++)
        sum = (sum + stair_num_arr[N][i]) % MOD_NUM;
    
    printf("%d\n", sum % MOD_NUM);
}

