#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)

{
    int case_num;    // 테스트 케이스 수
    cin >> case_num; // 테스트 케이스 수 입력

    for (int t = 0; t < case_num; t++){
        string func;    // 수행할 함수

        cin >> func;    // 수행할 함수 입력
        
        int num_in_arr;    // 배열에 들어있는 수 
        cin >> num_in_arr;
        
        string arr;

        cin >> arr; //배열 입력

        deque<int> dq; //덱

 

        string temp; //두 자릿수 이상 숫자를 위하여

        for (int i = 0; i < arr.length(); i++)
            if (arr[i] == '[')
                continue;

            else if ('0' <= arr[i] && arr[i] <= '9')
                temp += arr[i];

            else if (arr[i] == ',' || arr[i] == ']'){
                if (!temp.empty()){

                dq.push_back(stoi(temp));
                temp.clear();
                }

            }
        
        bool print = true; //error가 아닐 경우 true
        bool left = true; //뒤집어져있지 않으면 true
        
        for (int i = 0; i < func.length(); i++)
            if (func[i] == 'R')    // R 인경우
                left = !left;

            else{

                if (dq.empty()){
                    print = false;
                    cout << "error\n";    // false인 경우 에러 출력
                    break;
                }
                
                else
                    if (left)
                        dq.pop_front();

                    else
                        dq.pop_back();

            }
            if (print){
                if (left){
                    cout << "[";
                    
                    while (!dq.empty()){
                        cout << dq.front();    // 제일 왼쪽 수 출력
                        dq.pop_front();        // 그리고 바로 pop
                        
                        if (!dq.empty()){
                            cout << ",";
                        }
                    }

                    cout << "]\n";
                }

                else{
                    cout << "[";
                    while (!dq.empty()){
                        cout << dq.back();    // 제일 오른쪽 수 출력
                        dq.pop_back();        // 그리고 바로 pop

                        if (!dq.empty()){
                            cout << ",";
                        }                
                    }                    
                    cout << "]\n";
                }
            }
    }
    return 0;
}

