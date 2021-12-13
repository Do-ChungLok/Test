#include <stdio.h>
#include <algorithm>

using namespace std;

#define ARRAY_SIZE_MAX 100001

int input_arr[ARRAY_SIZE_MAX];     // 입력한 정수가 들어갈 배열

// 이진 탐색 함수
void Binary_Search_func(int input_num, int key){    // input_num : 첫번째로 입력한 정수의 개수, key : 두번째로 입력한 정수들
    
    int start_num = 0;
    int end_num = input_num - 1;
    int mid_num;
    
    while(end_num - start_num >= 0){
        mid_num = (start_num + end_num) / 2;    // 이진 탐색을 위해 중간값을 설정
        
        if (input_arr[mid_num] == key){    // 두번째로 입력한 정수값과 첫번재로 입력한 정수들의 배열의 중앙값과 같으면 '1' 출력
            printf("1\n");
            return;
        }
        
        else if (input_arr[mid_num] < key){    // 두번째로 입력한 정수값이 중앙값보다 클때 범위의 시작 정수의 크기를 늘림 
            start_num = mid_num + 1;
        }
        
        else if (input_arr[mid_num] > key){    // 두번째로 입력한 정수값이 중앙값보다 작을때 범위의 끝 정수의 크기를 줄임 
            end_num = mid_num - 1;
        }
    }
    
    printf("0\n");
    return;
    
}

int main()
{
    int integer_num1, integer_num2;    // 첫번째와 두번째로 입력할 정수 개수
    int input2;    // 두번째로 입력하는 정수
    
    scanf("%d", &integer_num1);    // 첫번째 정수 개수 입력
    
    for (int i = 0; i < integer_num1; i++){    // 정수 입력
        scanf("%d", &input_arr[i]);
    }
    
    sort(input_arr, input_arr + integer_num1);    // 입력한 정수들을 오름차순으로 정렬
    
    scanf("%d", &integer_num2);    // 두번째 정수 개수 입력
    
    for (int i = 0; i < integer_num2; i++){    
        scanf("%d", &input2);      // 두번째 정수 입력
        Binary_Search_func(integer_num1, input2);
    }    

    return 0;   
}
