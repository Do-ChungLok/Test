#include <stdio.h>
#include <string.h>

#define STR_MAX 51

int main()
{
    char input_str[STR_MAX] = {};    // 입력한 식을 저장할 배열
    int arr[STR_MAX] = {};      // 합을 저장할 배열
    
    scanf("%s", input_str);     // 식을 입력
    
    int len = strlen(input_str);
    int j = 0, temp = 0, sum = 0, minimum = 0;

    for (int i = 0; i <= len; i++) {
        if (input_str[i] == '-' || i==len) {    // 연산기호 '-'를 만난다면 더해서 새로운 배열에 저장
            sum = sum + temp;
            arr[j] = sum;
            j++;
            temp = 0;        // temp를 다시 초기화
            sum = 0;         // sum을 다시 초기화
        }
        
        else if (input_str[i] == '+') {        // 연산기호 '+'를' 만나는 경우 숫자를 sum에 저장
            sum = sum + temp;
            temp = 0;
        }
        
        else {                           // 'char str[]'로 문자형이니까 숫자로 받기 위해 -'0'을 해야함
            temp = temp * 10;
            temp = temp + input_str[i] - '0';
        }
    }

    minimum = arr[0];
    
    for (int i = 1; i < j; i++) {
        minimum = minimum - arr[i];        // 새로운 배열에 저장된 모든 값을 처음 배열 값에서 빼줌
    }
    
    printf("%d", minimum);
}
