#include <stdio.h>

long long solve_func(long long num1, long long num2, long long num3)
{
    if (num2 == 0){    // ex) A^0 = 1
        return 1;
    }
    
    else if (num2 == 1){    // A^B % C 에서 B가 1이면 A^1 % C == A % C
        return num1 % num3;
    }
    
    else if (num2 % 2 == 0){    // num2가 짝수인 경우  ex) A^B = A^1/2B * A^1/2B
        long long tmp = solve_func(num1, num2 / 2, num3);    
            return (tmp * tmp) % num3;
    }
    
    else{                       // num2가 홀수인 경우  ex) A^B = A^1/2B * A^1/2B * A
        long long tmp2 = solve_func(num1, (num2 - 1) / 2, num3);
            return (tmp2 * tmp2) % num3 * num1 % num3;
    }
}

int main()
{
    long long input1, input2, input3;    // 입력 변수
       
    scanf("%lld %lld %lld", &input1, &input2, &input3);    // 변수 입력
      
    printf("%lld", solve_func(input1, input2, input3));    // 출력
    
    return 0;
       
}
