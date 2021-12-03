#include <stdio.h>

#define ARRAY_SIZE_MAX 501

int Max(int num1, int num2)
{
    if (num1 > num2)
        return num1; 
    else
        return num2;
}

int main(void) {
    int input_num;
    int i, j, result = 0, max = 0;
    int array_num[ARRAY_SIZE_MAX] = {};
    int array_min[ARRAY_SIZE_MAX] = {};
     
    scanf("%d", &input_num);    // 두 전봇대 사이 전깃줄의 개수

    for (i = 1; i <= input_num; i++) {
        scanf("%d", &j);
        scanf("%d", &array_num[j]);
    }

    for (i = 1; i <= ARRAY_SIZE_MAX; i++) {    // 가장 긴 증가 수열 구하는 것과 풀이 같음
        if (array_num[i] != 0){         // 인덱스가 '0'이외의 값만 사용
            max = 0;
            for (j = 0; j < i; j++) {
                if (array_num[i] > array_num[j]) {    // 현재 값 (array_num[i])보다 작은 이전값 (array_num[j]) 중에서
                    if (array_min[j] > max) {         // 가장 큰 array_min[j] 값을 찾고 max에 저장
                        max = array_min[j];
                    }
                }
            }
            array_min[i] = max + 1;     
            result = Max(result, array_min[i]);
        }
    }
    printf("%d", input_num - result);    // 전체 전깃줄 - 연결 가능한 최대 전깃줄
}
