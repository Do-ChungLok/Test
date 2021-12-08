#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stack>

#define INPUT_STACK_ARRAY_SIZE_MAX 100001

using namespace std;

int main(void) {
    stack<int> st1; // 입력 배열 넣을 스택
    stack<int> st2; // 비교할 스택
    
    int i, j = 0; 
    int case_num = 0, temp = 0, check = 0;
    int arr[INPUT_STACK_ARRAY_SIZE_MAX];         // 입력한 정수 저장할 배열
    char result[INPUT_STACK_ARRAY_SIZE_MAX];     // 결과 출력할 배열
    
    scanf("%d", &case_num);    // 몇개의 수열을 입력할지 

    for (i = 1; i <= case_num; i++) {
        scanf("%d", &arr[i]);    // 수열 입력
    }
    for (i = case_num; i > 0; i--) {
        st1.push(arr[i]);
    }
    i = 0;
    while (!st1.empty()) {
        if (st1.top() > i) {            //스택에 있는 수가 목표 수 보다 낮은 경우
                                        //push(+)
            i++;
            st2.push(i);
            result[j] = '+';
            j++;
        }
        else if (st1.top() < st2.top()) {       //스택의 상단부분의 수가 목표 수 보다 높은경우
                                                // check를 1 저장 -> 원하는 수열을 만들 수 없음
            check = 1;
            break;
        }
        else if (!st2.empty() && st1.top() == st2.top()){   //스택 상단부분의 수가 목표 수와 같은 경우
                                                           //pop(-)
            st1.pop();
            st2.pop();
            result[j] = '-';
            j++;
        }
    }
    if (check == 1) {        
        printf("NO");
    }
    else {
        for (int k = 0; k < j; k++) {
            printf("%c\n", result[k]);    // 결과 출력
        }
    }
}
