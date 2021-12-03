#include <stdio.h>

#define NUMBER_SIZE_MAX 101
#define WEIGHT_SIZE_MAX 100001
#define VALUE_SIZE_MAX 1001

int Max(int num1, int num2)
{
    if (num1 > num2)
        return num1; 
    else
        return num2;
}

int main()
{
    int number, limit_weight;             // 물픔의 수, 무게
    int weight[WEIGHT_SIZE_MAX] = {0,};   // 버틸 수 있는 무게를 넣을 배열
    int value[VALUE_SIZE_MAX] = {0,};     // 물건의 가치를 넣을 배열
    int value_sum_max[NUMBER_SIZE_MAX][WEIGHT_SIZE_MAX] = {0,};  // 무게들 가치들의 합 배열
    
    scanf("%d %d", &number, &limit_weight);    // 물품의 수, 무게 입력
    
    for (int i = 1; i <= number; i++){          
        scanf("%d %d", &weight[i], &value[i]); // 무게 배열, 가치 배열 입력
    }
    
    for (int i = 1; i <= number; i++){
        for (int j = 1; j <= limit_weight; j++){
            
            if (j >= weight[i]){    // 'i' 번째 물건을 담을때
                value_sum_max[i][j] = Max( value_sum_max[i - 1][j], value_sum_max[i - 1][j - weight[i]] + value[i] );
            }                        // ex) weight[3]을 담을 때 --> Max( value_sum_max[2][7], value_sum_max[2][7 - 3] + value[3] ) --> 13 vs 14 --> 14
            
            else    // 'i' 번째 물건을 안 담을때
                value_sum_max[i][j] = value_sum_max[i - 1][j];
        }
    }
    
    printf("%d\n", value_sum_max[number][limit_weight]);
    
    return 0;
}
