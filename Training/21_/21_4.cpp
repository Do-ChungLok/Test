#include <stdio.h>
 
#define ARRAY_SIZE_MAX 1000001
 
int tree_num;         // 나무의 개수
int need_tree_length;    // 가져가려고 하는 나무의 길이

long long tree_arr[ARRAY_SIZE_MAX] = { };    // 가지고 있는 나무의 높이를 저장할 배열
 
long long Binary_Search_func(long long left, long long right)    // 이진 탐색 함수
{
    while (left <= right){
        long long sum = 0;
 
        long long middle = (left + right) / 2;
 
        for (int i = 0; i < tree_num; i++){
            if (tree_arr[i] - middle > 0){    // 나무의 높이와 중간값의 차이가 0보다 커야 sum을 구함
                sum += tree_arr[i] - middle;
            }
        }
        
        if (sum == need_tree_length)    // 합과 가져가려고 하는 나무 길이가 같다면 바로 middle값 반환
            return middle;
        
        else if (sum < need_tree_length)    // sum이 가져가려고 하는 나무 길이보다 작다면 right 값 조정
            right = middle -1;
        
        else if (sum > need_tree_length)    // sum이 가져가려고 하는 나무 길이보다 작다면 left 값 조정
            left = middle +1;
    }
 
    return right;
}
 
int main(void)
{
    long long tree_max_high = 0;    // 가지고 있는 제일 긴 나무의 높이
    long long result = 0;
     
    scanf("%d %d", &tree_num, &need_tree_length);    // 나무의 개수, 가져가려고 하는 나무의 길이 입력
 
    for (int i = 0; i < tree_num; i++){
        scanf("%lld", &tree_arr[i]);    // 가지고 있는 나무의 높이 입력
   
        if (tree_max_high < tree_arr[i]) 
                tree_max_high = tree_arr[i];    // 가지고 있는 나무의 높이 중 제일 긴 나무의 높이 저장
    }
	
    result = Binary_Search_func(1, tree_max_high);	
    	 
    printf("%lld\n", result);    // 출력
 
    return 0;
}

