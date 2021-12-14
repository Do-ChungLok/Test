#include <stdio.h>
#include <algorithm>

using namespace std; 

int array_size;    // 배열의 크기
int output_order;    // 출력할 배열 원소의 순서
int result;    // 결과값
int ans;    // 이진 탐색 함수에서 최종 반환값

int Binary_Search_func(int left, int right)    // 이진 탐색 함수
{   
    while (left <= right){
        int middle = (left + right) / 2;
        int count = 0;
        
        for (int i = 1; i <= array_size; i++){
            count += min(middle / i, array_size);    // middle보다 작은 원소 개수 count
            
        }
            
        if (count < output_order){    // count < 출력할 배열 원소의 순서
            left = middle + 1;    // 간격을 늘림
        }
        
        else if (count >= output_order){    // count >= 출력할 배열 원소의 순서
            ans = middle;
            right = middle - 1;    // 간격을 줄임
        }   
    }
    return ans;
}

int main(void)
{   
    scanf("%d", &array_size);    // 배열의 크기
    scanf("%d", &output_order);  // 출력할 배열의 순서
    
    result = Binary_Search_func(1, output_order);
    
    printf("%d\n", result);    
    
    return 0;
}

