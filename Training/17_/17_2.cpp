#include <stdio.h>

#define INPUT_FACTOR_SIZE_MAX 1000000

int main()
{
    int factor_num;      // 진짜 약수의 갯수
    int input_factor[INPUT_FACTOR_SIZE_MAX] = {};    // 진짜 약수
    int result_number;   // 구하고자 하는 정수
    int temp;

    scanf("%d", &factor_num);
        
    for (int i = 0; i < factor_num; i++){    // 진짜 약수들을 오름차순으로 정렬하여 구하고자 하는 정수에 접근
        scanf("%d", &input_factor[i]);
        
        for (int j = 0; j < factor_num; j++){
            if (input_factor[i] < input_factor[j]){
                temp = input_factor[j];
                input_factor[j] = input_factor[i];
                input_factor[i] = temp;
            }
        }    
    }
    
    
    result_number = input_factor[0] * input_factor[factor_num - 1];    // 오름차순 정렬한거에서 맨처음 숫자와 맨끝 숫자를 곱하면 구하고자 하는 정수가 나옴

    printf("%d\n", result_number);

    return 0;
    
}
