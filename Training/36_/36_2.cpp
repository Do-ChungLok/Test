#include <stdio.h>
#include <cmath>

#define INTEGER_n_SIZE_MAX 500000
#define ARRAY_SIZE_MAX 20
 
int table[ARRAY_SIZE_MAX][INTEGER_n_SIZE_MAX];    // 함수, log2(500,000) > 19

int main() 
{
    int integer_num;    // 정수 개수 
    scanf("%d", &integer_num);    // 정수 개수 입력
    
    for (int i = 1; i <= integer_num; i++) {
        scanf("%d", &table[0][i]);    // 함수 입력
    }
    
    for (int k = 1; k < log2(INTEGER_n_SIZE_MAX) + 1; k++) {
        for (int i = 0; i <= integer_num; i++) {
            int tmp = table[k - 1][i];
            table[k][i] = table[k - 1][tmp];
        }
    }
    
    int querry_num;    // 쿼리 개수 
    scanf("%d", &querry_num);    // 쿼리 개수 입력
    
    while (querry_num--) {    // 쿼리 개수 만큼 반복
        int n, x; 
        scanf("%d %d", &n, &x);    // 정수 n, x 입력
        
        for (int i = 0; n; i++) {
        //ex) 7 -> 0111 이므로 1 -> 2 -> 4칸씩 움직임
            if (n & 1) {
                x = table[i][x];    
            }
            
            n >>= 1;
        }
        
        printf("%d\n", x);    // 출력
    }
    
    return 0;
}
