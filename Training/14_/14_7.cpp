#include <iostream>

#define MIN 1000000000
#define MAX -1000000000    

using namespace std;

int N;                // 수의 개수
int operands[11];     // 수열을 저장할 배열
int operators[4];     // 연산자의 개수를 저장할 배열
int my_min = MIN;     // 최소값을 저장할 변수
int my_max = MAX;     // 최대값을 저장할 변수

void find_answer(int result, int num)
{
    if (num == N)
    {
        if(result > my_max)
            my_max = result;
        if(result < my_min)
            my_min = result;
        return;
    }
    for (int i = 0; i < 4; i++){
        if (operators[i] > 0){
            
            operators[i]--; // 연산자 하나 사용했으므로 1개 줄여줌
            
            if (i == 0)
                find_answer(result + operands[num], num+1);
            else if (i == 1)
                find_answer(result - operands[num], num+1);
            else if (i == 2)
                find_answer(result * operands[num], num+1);
            else if (i == 3)
                find_answer(result / operands[num], num+1);
            else{}
            
            operators[i]++; // 다른 연산자를 사용할 것이므로 아까 줄였던 연산자 개수 늘려줌
        }
    }
    return;
}

int main() 
{
    cin >> N;
    
    for (int i = 0; i < N; i++)    // 수의 개수 입력
        cin >> operands[i];
    
    for (int i = 0; i < 4; i++)    // 연산자는 4개
        cin >> operators[i];
    
    find_answer(operands[0],1);      // [0]을 초기값으로 설정
    
    cout << my_max << "\n" << my_min;

}
