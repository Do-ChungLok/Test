#include <stdio.h>

// 뒤에 '0'이 나오려면 10의 제곱의 개수만큼 나옴. 즉 10은 2 * 5 이고, 입력값 중에
// 2의 배수는 5의 배수보다 항상 많으니, 5의 배수의 개수만 구하면 됨

int main()
{
    int input;    // 정수 입력
    int multiple_5 = 0;    // 5의 배수
    int multiple_25 = 0;   // 25의 배수
    int multiple_125 = 0;  // 125의 배수
        
    scanf("%d", &input);
    
    multiple_5 = input / 5;      // 입력한 수를 5로 나누었을때 개수 체크 -> 5의 배수의 개수
    multiple_25 = input / 25;    // 입력한 수를 25로 나누었을때 개수 체크 -> 25의 배수의 개수
    multiple_125 = input / 125;  // 입력한 수를 125로 나누었을때 개수 체크 -> 125의 배수의 개수
    
    printf("%d", multiple_5 + multiple_25 + multiple_125);
    
    return 0;
}
