#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE_MAX 8001
#define POSITIVE_INTEGER_SIZE_MAX 4000

int compare(const void* coord1, const void* coord2){
	int num1 = *(int*)coord1;
	int num2 = *(int*)coord2;

	if (num1 > num2)
		return 1;
	else if (num1 < num2)
		return -1;
	else
		return 0;
}

int arithmetic_mean(int list[], int N){    // 산술평균
    double sum = 0;
    for(int i=0; i<N; i++){
        sum += (list[i]);
    }
    return round(sum/N);    // int형 계산하면 반내림 하니까 'round'로 반올림 해줌
}

int median(int list[], int N){    // 중앙값
    if(N == 1)
        return list[0];
    else
        return list[(N-1)/2];
}

int second_min(int list[], int N){    // 두번째로 작은 최빈값
	int arr[SIZE_MAX] = {}; // -4000 ~ 4000까지 0 포함 8001개 배열
	int i, index, max = 0, cnt = 0;

	for (i = 0; i < N; i++){
		index = list[i] + POSITIVE_INTEGER_SIZE_MAX;    // -4000부터 시작하는 것을 0부터 시작하는것으로 바꾸기 위해 +4000 해줌
		arr[index] += 1;
		
		if (arr[index] > max)
			max = arr[index];
	}

	for (i = 0, index = 0; i < SIZE_MAX ; i++){
	
		if (arr[i] == 0)
			continue;

		if (arr[i] == max){
		
			if (cnt == 0){
				index = i;
				cnt += 1;
			}
			
			else if (cnt == 1){
				index = i;
				break;
			}
		}
	}
	return index - 4000;    // 처음에 입력값 +4000 했으니 원래 초기값으로 

}

int range(int list[], int N){    // 범위 출력
    int max = list[N-1];    // 제일 오른쪽 값
    int min = list[0];      // 제일 왼쪽 값
    
    return max - min;       // 제일 오른쪽 값 - 제일 왼쪽 값
}

int main(){

    int N;
    int *list;
    
    scanf("%d",&N);
    list = (int*)calloc(N, sizeof(int));
    
    for(int i=0; i<N; i++){
        scanf("%d",&list[i]);
    }
    
    qsort(list, N, sizeof(list[0]), compare);	// 정렬
    
    printf("%d\n", arithmetic_mean(list, N));	// 산술평균
    printf("%d\n", median(list, N));		// 중앙값
    printf("%d\n", second_min(list, N));	// 두번째로 작은 최빈값
    printf("%d\n", range(list, N));		// 범위

    return 0;
}
