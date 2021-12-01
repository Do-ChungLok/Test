#include <stdio.h>

#define SIZE_MAX 21

int W_arr[SIZE_MAX][SIZE_MAX][SIZE_MAX] = {};    // 3차원 배열 선언

int W_func(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }

    if(a > 20 || b > 20 || c > 20){
        return W_func(20, 20, 20);
    }

    if(W_arr[a][b][c] != 0){
        return W_arr[a][b][c];
    }

    if(a < b && b < c){
        W_arr[a][b][c] = W_func(a, b, c - 1) + W_func(a, b - 1, c - 1) - W_func(a, b - 1, c);
    }
    
    else{
        W_arr[a][b][c] = W_func(a - 1, b, c) + W_func(a - 1, b - 1, c) + W_func(a - 1, b, c - 1) - W_func(a - 1, b - 1, c - 1);
    }
    
    return W_arr[a][b][c]; 
}

int main()
{
    int a, b, c;              
    
    while(1){
        scanf("%d %d %d", &a, &b, &c);    // a, b, c 입력 
        
        if(a == -1 && b == -1 && c == -1){    // 입력의 마지막
            break;
        }
        
        printf("w(%d, %d, %d) = %d\n", a, b, c, W_func(a, b, c));
    }

    return 0;
}
