#include <iostream>
#include <stack>

#define ARRAY_SIZE_MAX 1000000

using namespace std;

int main() 
{
	stack<int> st;   // 스택 선언
    int case_num;    // 케이스 개수
    
    int sequence[ARRAY_SIZE_MAX];    // 입력할 수열을 저장할 배열
    int nge[ARRAY_SIZE_MAX];         // 오큰수를 저장할 배열
    
    scanf("%d", &case_num);          // 케이스 개수 입력
    
    for (int i = 0; i < case_num; i++){
        scanf("%d", &sequence[i]);   // 수열 입력
    }
    
    for (int j = case_num - 1; j >= 0; j-- ){
        while(!st.empty() && st.top() <= sequence[j]){
            st.pop();      // 현재 스택이 비어있지 않고, 스택의 top 값이 입력한 수열보다 작지 않다면 pop
        }
        
        if (st.empty()){    // 현재 스택이 비어있다면 nge 값은 -1
            nge[j] = -1;
        }
        
        else{               // 현재 스택이 비어있지 않다면 nge 값은 top이 됨
            nge[j] = st.top();
        }
        
        st.push(sequence[j]);    // 순서대로 연산 후 push
    }
    
    for (int k = 0; k < case_num; k++){
        printf("%d ", nge[k]);    // nge 출력
    }
    
  
}
