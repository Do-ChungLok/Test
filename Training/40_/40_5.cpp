#include <stdio.h>
#include <vector>

#define MOD 1000000007

using namespace std;
using ll = long long;
using vll = vector <ll>;
using matrix = vector <vll>;    // 2차원 벡터

matrix operator*(matrix &a, matrix &b) 
{
    matrix result(2, vll(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] += a[i][k] * b[k][j] % MOD;
                result[i][j] = (result[i][j] + MOD) % MOD;    
                // MOD 계산시 음수 나오는 경우 방지 -> MOD 더하고 나누어줌
            }
        }
    }
    return result;
}

int main()
{
    ll col_size;    // 행열의 열 크기 
    scanf("%lld", &col_size);    // 열 크기 입력
    
    matrix A = {{4, -1}, {1, 0}};    // A
    matrix initial_value = {{1, 0}, {1, 0}};    // 초기값
    matrix ans = {{1, 0}, {0, 1}};
    
// F(n) = 3*F(n-2) + 2{F(n-4) + F(n-6) + F(n-8) +...+ F(0)}
// F(n-2) = 3*F(n-4) + 2{F(n-6) + F(n-8) + F(n-10) +...+ F(0)}
// F(n)-F(n-2) = 3*F(n-2) - F(n-4)
// -> F(n) = 4*F(n-2) - F(n-4)   
    
    if (col_size & 1 == 1) {    // 곱해서 0을 만들어 주기 위해
        printf("0");
    } 
    
    else {
        col_size /= 2;
        while (col_size) {
            if (col_size & 1 == 1) {
                ans = ans * A;
            }
            
            A = A * A;
            col_size /= 2;
        }
        ans = ans * initial_value;
        
        printf("%lld", ans[0][0] % MOD);    // 출력
    }
    
    return 0;
}
