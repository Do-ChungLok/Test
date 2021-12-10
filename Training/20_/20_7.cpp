#include <stdio.h>

#define ARRAY_MAX_SIZE 5

long long size1, size2;    // size1 : 행렬의 크기, size2 : size2 만큼 제곱
long long ori_arr[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE] = {};
long long temp_arr[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE] = {};
long long result_arr[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE] = {};


void print_result_arr(long long arr[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE])    // 행렬 출력
{
    for (int i =0; i < size1; i++){
        for (int j = 0; j < size1; j++){
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }
}

// 행렬끼리의 곱셈 함수
void Matrix_multiple(long long X[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], long long Y[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE])
{
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size1; j++)
		{
			temp_arr[i][j] = 0; // 행렬 초기화
			for (int k = 0; k < size1; k++)
				temp_arr[i][j] += (X[i][k] * Y[k][j]);

			temp_arr[i][j] %= 1000;
		}

	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size1; j++)
			X[i][j] = temp_arr[i][j];
}



int main()
{

    scanf("%lld %lld", &size1, &size2);    // ori(처음) 행렬의 row, col => size1  
    
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size1; j++){
            scanf("%lld", &ori_arr[i][j]);    // ori 행렬 원소 입력
        }
        result_arr[i][i] = 1;    // 결과 행렬을 단위행렬로 치환
    }
    while(size2 > 0){
        if (size2 % 2 ==1){    // 홀수인 경우
            Matrix_multiple(result_arr, ori_arr); // 결과 행렬 * ori 행렬
        }
        Matrix_multiple(ori_arr, ori_arr);    // 짝수인 경우
        size2 /= 2;
    }
        
    print_result_arr(result_arr); // ori 행렬을 'size2'번 만큼 곱한 결과 행렬
}
