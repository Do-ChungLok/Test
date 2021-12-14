#include <stdio.h>
 
#define ARRAY_SIZE_MAX 10001
 
int cable_num = 0;         // 오영식이 이미 가지고 있는 랜선의 개수
int need_cable_num = 0;    // 필요한 랜선의 개수
 
long long cable_arr[ARRAY_SIZE_MAX] = { };    // 랜선 길이 저장할 배열
 
long long Binary_Search_func(long long left, long long right)    // 이진 탐색 함수
{
    while (left <= right){
        int count = 0;
 
        long long middle = (left + right) / 2;    // left + right 하면 int로는 2^31-1 범위보다 크니 long long 사용
 
        for (int i = 0; i <= cable_num; i++){
            count += cable_arr[i] / middle;
        }
 
        // 내가 찾은 개수(count)가 need_cable_num 보다 더 크다면, 더 큰 수로 나눠야 하니 left를 증가시킴
        if (count >= need_cable_num){
            left = middle + 1;
        }
        
        else{ 
            right = middle - 1;
        }
    }
 
    return right;
}
 
int main(void)
{
    long long cable_max_length = 0;    // 만들 수 있는 최대 길이
    long long result = 0;
     
    scanf("%d %d", &cable_num, &need_cable_num);    // 이미 가지고 있는 랜선 개수, 필요한 랜선 개수 입력
 
    for (int i = 0; i < cable_num; i++){
        scanf("%lld", &cable_arr[i]);    // 이미 가지고 있는 랜선 길이 
 
        if (cable_max_length < cable_arr[i]) 
		cable_max_length = cable_arr[i];
    }
    
    result = Binary_Search_func(1, cable_max_length);
    
    printf("%lld\n", result);    // 출력
 
    return 0;
}

