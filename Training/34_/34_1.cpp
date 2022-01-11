#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

string n,m;    // 입력할 두 문자열
int result =0;
vector <int> result_vec;

vector<int> makeTable(string pattern)
{
    int pattern_size = pattern.size();
    vector <int> table(pattern_size,0);

    int j = 0 ; 
    for(int i = 1; i < pattern_size; i++) {    // i는 1부터 시작 접두 접미사 부분이 일치하는지 확인 
        while(j > 0 && pattern[i] != pattern[j]){    // i 인덱스의 값과 j 인덱스의 값이 일치하지 않으면
            j = table[j - 1];    // j - 1 인덱스 값을 j에 넣음
        }
        
        if (pattern[i] == pattern[j]) {    // i 인덱스랑 j 인덱스의 값이 같다면
            table[i] = ++j;    // table의 i위치에 현재 j 값의 + 1을 해서 넣음 
        }
    }
    
    return table;
}

void kmp(string parent, string pattern)
{
    vector<int> table = makeTable(pattern);
    int parent_size = parent.size();
    int pattern_size = pattern.size();
    int j = 0;
    
    for (int i = 0 ; i< parent_size; i++) {
        while(j > 0 && parent[i] != pattern[j]) {    // 패턴이랑 parent랑 다를 동안
 
            j = table[j-1];    // j 복귀 패턴
        }

        if (parent[i] == pattern[j]){    // 같을 때
           
            if (j == pattern_size -1){    // 온전하게 패턴 찾았을 때
                result_vec.push_back(i - pattern_size + 2); // 어느위치에서 찾았는지 
                j = table[j]; // 패턴 째로 스킵
                result ++; // 몇개 찾았는지
            }
            
            else {
                j++; 
            }
        }
    }
}

int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    getline(cin,n);    // 문자열 입력
    getline(cin,m);    // 문자열 입력
    vector <int> table = makeTable(m);
    kmp(n,m);    // kmp 함수 호출
    
    cout << result << endl;    // T 중간에 P가 몇 번 나타나는지 출력
    for(int i = 0 ; i < result_vec.size(); i++) {
        cout << result_vec[i] << " ";    // P가 나타나는 위치 출력
    }
    
    return 0;    
}
