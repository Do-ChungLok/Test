#include <stdio.h>

#define min(num1, num2) (num1 < num2 ? num1 : num2)

// 2의 배수 하나와 5의 배수 하나가 곱해지면 '0'이 카운트 됨
// ---> 그래서 2의 배수, 5의 배수 찾아야함

long long int i;
int five_multiple_count = 0, two_multiple_count = 0;

int Five_multiple_find(int num)    // 인수분해 할 때 나오는 5의 개수 찾기
{
    int count = 0;
    
    for (i = 5; num / i >= 1; i *= 5){
        count += num/i;
    }
    
    return count;
}

int Two_multiple_find(int num)    // 인수분해 할 때 나오는 2의 개수 찾기
{
    int count = 0;
    
    for (i = 2; num / i >= 1; i *= 2){
        count += num/i;
    }
    
    return count;
}

int main()
{
    int input1, input2;    // 정수1, 2 입력
    int five_multiple_count = 0, two_multiple_count = 0;

    scanf("%d %d", &input1, &input2);    // 정수1, 2 입력
    
    five_multiple_count += Five_multiple_find(input1);    // 조합식
    if (input2 != 0){
        five_multiple_count -= Five_multiple_find(input2);    
    }
    
    if (input1 != input2){
        five_multiple_count -= Five_multiple_find(input1 - input2);
    }
    
    two_multiple_count += Two_multiple_find(input1);       // 조합식
    if (input2 != 0){
        two_multiple_count -= Two_multiple_find(input2);
    }
    
    if (input1 != input2){
        two_multiple_count -= Two_multiple_find(input1 - input2);
    }
    
    printf("%d\n", min(two_multiple_count, five_multiple_count));    // 2의 배수와 5의 배수 중에 적은 개수가 '0'의 개수가 됨
    
    return 0;
        
        
}
