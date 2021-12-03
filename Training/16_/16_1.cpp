#include <stdio.h>

#define ARRAY_SIZE_MAX 11

int main()
{
    int input_num; // 동전 종류 갯수
    int sum_value; // 동전 가치의 합
    int each_value[ARRAY_SIZE_MAX] = {}; // 동전 각각의 가치 
    int result = 0; // 구하고자 하는 동전 개수의 최소값 
    
    scanf("%d %d\n", &input_num, &sum_value);
    
    for (int i = input_num - 1; i >= 0; i--){
       scanf("%d", &each_value[i]);    // 내림차순 정렬하기위해 i--를 통해 거꾸로 연산
    }
    
    for (int i = 0; i < input_num; i++){
        result += sum_value / each_value[i];    // 동전 개수의 최소 값을 연산하기 위해 '가치의 합' / '각각의 가치'
        sum_value %= each_value[i];    // '동전 가치의 합'을 '동전 하나의 단위의 가치' 로 나눈 '나머지'
    }
    
    printf("%d", result);
    
    return 0;
}
