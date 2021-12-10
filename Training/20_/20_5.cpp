// nCk = N! / (K!(N-K)!) = N! * (K!(N-K)!)^(-1)이고,
// 페르마의 소정리인 a^p ≡ a % p에서 양변에 a*2로 나누면, a^(p-2) ≡ a^(-1) % p이므로
// nCk = N! * (K!(N-K)!)^1000000005이다. 
// p = 1000000007, 우리 구해야 하는 건 nCk % P  -> a = N! * (K!(N-K)!)


#include <stdio.h>

#define MOD_INTEGER 1000000007

long long input1, input2, A, B, half;

long long solve_func(int num)
{
    if (num == 0){    
        return 1;
    }
    
    if (num % 2 == 1){    // nun이 홀수일때
        return B * solve_func(num - 1) % MOD_INTEGER;
    }
    
    else{                      
        half = solve_func(num / 2);    // nun이 짝수일때
        return half * half % MOD_INTEGER;
    }
}

int main()
{
    scanf("%lld %lld", &input1, &input2);

    A = 1;
    
    for (int i = input1; i >= input1 - input2 +1; i--){    // A = N*(N-1)* .... *(N-K+1)
        A = (A * i) % MOD_INTEGER;
    }
    
    B = 1;
    
    for (int i = 1; i <= input2; i++)    // B = K!
        B = (B * i) % MOD_INTEGER;
    
    
    B = solve_func(MOD_INTEGER - 2);    // B = (K!)^(p-2)
    
    printf("%lld", A * B % MOD_INTEGER);
       
    return 0;
       
}
