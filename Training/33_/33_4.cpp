#include <stdio.h>
#include <cstring>
#include <algorithm>
 
#define SET_SIZE_MAX 15
#define INPUT_SIZE_MAX 51

long long gcd(long long a, long long b)    // gcd : Greatest Common Divisor - 최대 공약수
{
    long long r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() 
{
    int set_num, last_input;    // 집합의 수, 마지막 입력 정수
    char tmp[SET_SIZE_MAX][INPUT_SIZE_MAX];
    long long dp[1 << SET_SIZE_MAX][101] = { 0 };    // dp[i][j] : 비트마스크 i에속한 집합의 순열에서 k로 나눈 나머지가 j가 되는 경우의 수                                                                                                       
    int ary[SET_SIZE_MAX] = { 0 }, size[SET_SIZE_MAX], octal[51];
    
    scanf("%d", &set_num);    // 집합의 수 입력
    for (int i = 0; i <set_num; i++) {
        scanf("%s", tmp[i]);    // 집합에 포함된 수 입력
        size[i] = strlen(tmp[i]);
    }
    
    scanf("%d", &last_input);    // 마지막 정수 입력
    octal[0] = 1;
    
    for (int i = 1; i < INPUT_SIZE_MAX; i++) {
        octal[i] = (octal[i - 1] * 10) % last_input;
    }
    
    for (int i = 0; i < set_num; i++) {
        for (int j = 0; j < size[i]; j++) {
            ary[i] = ((tmp[i][j] - '0') + ary[i] * 10) % last_input;
        }
    }
    
    dp[0][0] = 1;    // 초기값
    
    for (int i = 0; i < (1 << set_num); i++) {
        for(int j = 0; j < last_input; j++) {
            for (int t = 0; t < set_num; t++) {  
                if ((i&(1 << t)) == 0) {
                    dp[i | (1 << t)][(j * octal[size[t]] + ary[t]) % last_input] += dp[i][j];
                }
            }
        }
    }
 
    long long p = dp[(1 << set_num) - 1][0];
    long long q = 1;
    
    for (long long i = 2; i <= set_num; i++) {
        q *= i;
    }
    
    long long t = gcd(p, q);    // 기약분수를 구하기 위해 
    
    p /= t;
    q /= t;
    
    printf("%lld/%lld", p, q);    // 출력
    
    return 0;
}
