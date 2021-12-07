#include <stdio.h>

int factorial(int number)    // 이항계수를 구하기 위해 사용되는 팩토리얼 함수
{
    int result = 1;
    for (int i =1; i <= number; i++){
        result = result * i;
    }
    
    return result;
}

int main()
{
    int input1, input2;       // 입력 숫자 1, 2
    int denominator;          // 이항계수를 구하는데 사용되는 분자 변수
    int numerator;            // 이항계수를 구하는데 사용되는 분모 변수
    int binomial_coefficient; // 이항계수 변수 -> nCk = n! / k! * (n - k)!
    
    scanf("%d %d", &input1, &input2);    // 숫자1, 2 입력  
    
    denominator = factorial(input1);                            // 이항계수의 분자 -> n! --- n : input1 , k : input2
    numerator = factorial(input2) * factorial(input1 - input2); // 이항계수의 분모 -> k! * (n - k)!
    binomial_coefficient = denominator / numerator;             // 이항계수 변수
    
    printf("%d", binomial_coefficient);
    
}
