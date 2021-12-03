#include <stdio.h>

#define ARRAY_SIZE_MAX 100000

int Max(int num1, int num2)
    
{
    if (num1 > num2)
        return num1; 
    else
        return num2;
}

int main() 
{
    int n; // 입력할 정수의 개수 변수
    int input_num[ARRAY_SIZE_MAX] = {};    // 입력할 정수 저장할 배열
    int sequence_arr[ARRAY_SIZE_MAX] = {};    // 입력한 연속한 정수들의 합 배열
    int result = 0;    // 결과값
    
    scanf("%d", &n);    // 입력할 정수의 개수 변수 입력
    for (int i = 0; i < n; i++){
        scanf("%d", &input_num[i]);
    }
    
    result = input_num[0];
    sequence_arr[0] = input_num[0];
    
    for (int i=1 ; i < n; i++){    // sequence_arr[0] 에는 input_num[0] 값을 저장 했으니 'i=1' 부터
        sequence_arr[i] = Max(sequence_arr[i - 1] + input_num[i], input_num[i]);
        result = Max(sequence_arr[i], result);
    }    // 'n'까지의 연속 정수의 합 최대값은 'n-1'까지의 최대값 + 'n' 자신의 값 || 'n' 자신의값 둘 중 큰 값
    
    printf("%d\n", result);
    
    return 0; 
}
