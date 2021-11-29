#include <stdio.h>
#include <stdlib.h>
#define SIZE_MAX 1000001

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    
    if(num1 > num2){
        return 1;
    }
    else if(num1 < num2){
        return -1;
    }
    else
        return 0;
}

int main(){
    int N;
    int num_arr[SIZE_MAX]={};
    
    scanf("%d",&N);
    
    for(int i=0; i<N; i++)
        scanf("%d",&num_arr[i]);
    
    qsort(num_arr, N, sizeof(int), compare);    // qsort(정렬할 배열, 요소 개수, 요소 크기, 비교 함수)

    for(int i=0; i<N; i++){
        printf("%d\n",num_arr[i]);
    }
    return 0;
}
