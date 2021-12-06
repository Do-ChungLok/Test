#include <stdio.h>
#include <algorithm>

#define INPUT_SIZE_MAX 100
#define RESULT_ARR_SIZE_MAX 10000

using namespace std;

// 최대 공약수 구하는 함수 : gcf -> (greatest_common_factor)
int gcf(int num1, int num2)
{
    if (num1 % num2 == 0)
    {
        return num2;
    }
    return gcf(num2, num1 % num2);
}

int main()
{
    int case_num;                          // 케이스 개수
    int input_arr[INPUT_SIZE_MAX] = {};    // 종이에 적은 수(입력 수)를 저장할 배열
    int result[RESULT_ARR_SIZE_MAX] = {};  // 구하고자 하는 수를 저장할 배열
    int count = 0;
    
    scanf("%d", &case_num);                // 케이스 개수 입력
    
    for (int i = 0; i < case_num; i++){    
        scanf("%d", &input_arr[i]);        // 수 입력
    }
    
    sort(input_arr, input_arr + case_num);    // 입력 수 정렬
    
    int diff = input_arr[1] - input_arr[0];
    
    for (int i = 2; i < case_num; i++){
        diff = gcf(diff, input_arr[i] - input_arr[i - 1]);    // 입력한 수 input_arr[i] 와 input_arr[i-1]의 최대 공약수 
    }
    
    for (int i = 2; i * i <= diff; i++){    // 최대공약수의 공약수를 구함
        if (diff % i == 0){    // 같은 수를 걸러냄
            result[count++] = i;
            
            if (i * i != diff){    // 제곱근일때
                result[count++] = diff / i;
            }
        }
    }
    
    result[count++] = diff;
    
    sort(result, result + count);    // 오름차순으로 정렬 후 출력
    for (int i = 0; i < count; i++){
        printf("%d ", result[i]);
    }

    return 0;    
}
