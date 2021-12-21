#include <stdio.h>
#include<algorithm>

#define ARRAY_SIZE_MAX 1000001 

using namespace std;

int sequence_num;    // 수열의 수
int seq_arr[ARRAY_SIZE_MAX] = { };
int x;    // 입력하는 정수x
int left, right;    // 정렬된 수열에서 왼쪽에서 시작과 오른쪽에서 시작하는 기준점
int result;    // 쌍의 개수

int main()
{
    scanf("%d", &sequence_num);    // 수열의 수 입력
    
    for (int i = 0; i < sequence_num; i++){
        scanf("%d", &seq_arr[i]);    // 수열에 포함된 수 입력        
    }
    
    scanf("%d", &x);    // 수열에 포함된 값 두개의 합이 될 정수 입력
    
    sort(seq_arr, seq_arr + sequence_num);    // 오름차순 정렬
    
    left = 0;    // 수열의 맨 왼쪽 기준점
    right = sequence_num - 1;    // 수열의 맨 오른쪽 기준점
    
    while(left < right){
        if (seq_arr[left] + seq_arr[right] == x){
			result++;    // 쌍 ++
			right--;     // 정렬된 수열에서 오른쪽 기준점만 왼쪽으로 1칸 이동
			
		}
		else if (seq_arr[left] + seq_arr[right] > x){
			right--;     // 정렬된 수열에서 오른쪽 기준점만 왼쪽으로 1칸 이동   
		}
        
		else if (seq_arr[left] + seq_arr[right] < x){
			left++;      // 정렬된 수열에서 왼쪽 기준점만 오른쪽으로 1칸 이동  
		}
    }
    
    printf("%d", result);
    
    return 0;
}
