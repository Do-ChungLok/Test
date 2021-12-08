#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stack>

#define STRING_SIZE_MAX 101

using namespace std;

int main(void) {

    while (1) {
        stack<char> stack;    // 스택 선언
        int i;
        char str[STRING_SIZE_MAX];    // 입력할 문자열을 저장할 배열
        int check = 1;

        cin.getline(str, STRING_SIZE_MAX);    // 문자열 입력
        int len = strlen(str);                // 입력한 문자열 길이

        if (str[0] == '.')     // 맨 처음 입력이 '.'이면 탈출
            break;

        for (i = 0; i < len; i++) {    // '(' 또는 '[' 가 오면 push
            if (str[i] == '(' || str[i] == '[') {
                stack.push(str[i]);
            }
            else if (str[i] == ')') {    // ')'가 올 경우에 스택이 비어있지 않고, 스택의 top값이  '(' 일 경우 pop
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                }
                else {
                    check = 0;           // ')'가 올 경우에 스택이 비어있고, 스택의 top값이  '(' 이 아닐 경우 check값을 0, 탈출
                    break;
                }
            }
            else if (str[i] == ']') {    // ']'가 올 경우에 스택이 비어있지 않고, 스택의 top값이  '[' 일 경우 pop
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                }
                else {
                    check = 0;           // ']'가 올 경우에 스택이 비어있고, 스택의 top값이  '[' 이 아닐 경우 check값을 0, 탈출
                    break;
                }
            }
        }

        if (check == 1 && stack.empty()) {     // check 값이 1 && 스택이 비어 있으면 yes
            printf("yes\n"); 
        }
        
        else {                                 // check 값이 1이 아니고 && 스택이 비어 있지 않으면 no
            printf("no\n"); 
        }
    }
}
