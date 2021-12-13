#include <iostream>

#define ARRAY_MAX_SIZE 2
#define MOD_INTEGER 1000000007



// 피보나치수를 행렬로 표현 -> [[1 1], [1 0]]^n = 나오는 2X1 행렬의 [1][0](=2행 1열) 과 같다.
// 오버 플로우 방지를 위해 long long 선언

void Matrix_multiple(long long mat1[][ARRAY_MAX_SIZE], long long mat2[][ARRAY_MAX_SIZE]){
    long long tmp[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];
    long long temp;
 
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            temp = 0;
            for(int k = 0; k < 2; k++){
                temp += (mat1[i][k] * mat2[k][j]);
            }
            tmp[i][j] = temp % MOD_INTEGER;
        }
    }
 
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            mat1[i][j] = tmp[i][j];
        }
    }
 
    return;
}
 
int main() {
    long long ori_mat[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE] = {1, 1, 1, 0};    // 피보나치 행렬의 사용되는 행렬
    long long res[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE] = {1, 0, 0, 1};    // 결과 값의 행렬
    long long input;
 
    scanf("%lld", &input);
        
    while(input > 0){
        if(input % 2 == 1){    // 홀수인 경우
            Matrix_multiple(res, ori_mat);    // 결과행렬 * 처음행렬
        }   
       
        Matrix_multiple(ori_mat, ori_mat);    // 짝수인 경우
        
        input /= 2;   
      
    }
    
    printf("%lld", res[1][0]);
}
