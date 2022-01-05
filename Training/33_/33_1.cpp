#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
 
int cal_num;    // 연산의 개수
int num;    // 연산에 사용될 수
int BIT;    // 비트마스크
string input;
 
int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //scanf("%d", &cal_num);    // 연산의 개수 입력
    cin >> cal_num;     // 연산의 개수 입력
    while (cal_num--) {

        // scanf("%s", input);    
        input.clear();
        cin >> input;    // 문자열 입력
        if (input == "add") {
            cin >> num;    // 연산에 사용될 수 입력
            // scanf("%d", &num);   
            BIT |= (1 << num);
        }
        
        else if (input == "remove") {
            cin >> num;    // 연산에 사용될 수 입력
            // scanf("%d", &num);    
            BIT &= ~(1 << num);
        }
        
        else if (input == "check") {
            cin >> num;    // 연산에 사용될 수 입력
            // scanf("%d", &num);    
            
            if (BIT & (1 << num)) {   
                cout << 1 << '\n';
                // printf("1\n");
            }
            else {
                cout << 0 << '\n';
               // printf("0\n");
            }
        }
        
        else if (input == "toggle") {
            cin >> num;    // 연산에 사용될 수 입력
            // scanf("%d", &num);    
            BIT ^= (1 << num);    // XOR : 같으면 '0', 다르면 '1' 출력
        }
        
        else if (input == "all") {
            BIT = (1 << 21) - 1;    // (1 << 원소의 개수 + 1) -1
        }
        
        else if (input == "empty") {
            BIT = 0;
        }
    }
    return 0;
}
