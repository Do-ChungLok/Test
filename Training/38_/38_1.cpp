#include <stdio.h>

#define ARRAY_SIZE_MAX 100001

int main()
{
    int input_num;    // 수의 개수
    int sum_num;      // 합의 개수
    int input = 0;    // 입력 수 
    int start;    // 시작 구간
    int end;    // 끝 구간
    int sum[ARRAY_SIZE_MAX] = { };    // 합
    
    scanf("%d %d", &input_num, &sum_num);    // 수의 개수, 합의 개수 입력
    
    for (int i = 1; i <= input_num; i++) {
        scanf("%d", &input);    // 수 입력
        sum[i] = sum[i - 1] + input;
    }
    
    for (int j = 0; j < sum_num; j++) {
        scanf("%d %d", &start, &end);    // 시작, 끝 구간 입력
        printf("%d\n", sum[end] - sum[start - 1]);    // (끝 구간까지의 합) - (시작 -1 구간까지의 합)
    }
    //    i    0    1    2    3    4
    //  value  5    4    3    2    1
    //  sum[i] 5    9    12   14   15
 
    return 0;
    
}
