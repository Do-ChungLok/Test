#include <stdio.h>

#define ARRAY_MAX_SIZE 102

int main()
{
    int size1, size2, size3;    // size1 : data1 배열의 row, size2 : data1 배열의 col, data2 배열의 row, size3: data2 배열의 col
    int data1[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE] = {};
    int data2[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE] = {};
    int result_data[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE] = {};
    
    scanf("%d %d", &size1, &size2);    // data1 행렬의 row, col 입력
    
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size2; j++){
            scanf("%d", &data1[i][j]);    // data1 행렬 원소 입력
        }
    }
    
    scanf("%d %d", &size2, &size3);    // data2 행렬의 row, col 입력
    
    for (int i = 0; i < size2; i++){
        for (int j = 0; j < size3; j++){
            scanf("%d", &data2[i][j]);    // data2 행렬 원소 입력
        }
    }     
  
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size3; j++){
            for (int k = 0; k < size2; k++){    // dat1 행렬 * data2 행렬 곱해서 나온 새로운 행렬의 크기는 data1 행렬의 row(size1) X data2 행렬의 col(size3)
                result_data[i][j] += data1[i][k] * data2[k][j]; 
            }
        }     
    }   
    
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size3; j++){
            printf("%d ", result_data[i][j]);    // 새로운 행렬 출력
           
        }
        printf("\n");
    }     
}
