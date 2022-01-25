#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

int dp[15 * 15][1 << 14];
int col_size, row_size;    // 세로, 가로 크기
string value;    // 두부 등급

int calValue(string s)
{
    if (s[0] > s[1]) {
        swap(s[0], s[1]);
    }
                                      
    if (s[0] == 'A') {                //     A   B   C   D   F
        if (s[1] == 'A') {            // A  1 0  8   7   5   1 
            return 10;                // B   8   6   4   3   1
        }                             // C   7   4   3   2   1 
        if (s[1] == 'B') {            // D   5   3   2   2   1
            return 8;                 // F   1   1   1   1   0  
        }
        if (s[1] == 'C') {
            return 7;  
        }     
        if (s[1] == 'D') {
            return 5;    
        }        
        if (s[1] == 'F') {
            return 1;   
        }     
    } 
    
    else if (s[0] == 'B') {
        if (s[1] == 'B') {
            return 6;
        }
        if (s[1] == 'C') {
            return 4;
        }
        if (s[1] == 'D') {
            return 3;
        }
        if (s[1] == 'F') {
            return 1;
        }
    } 
    
    else if (s[0] == 'C') {
        if (s[1] == 'C') {
            return 3;
        }
        if (s[1] == 'D') {
            return 2;
        }
        if (s[1] == 'F') {
            return 1;
        }
    } 
    
    else if (s[0] == 'D') {
        if (s[1] == 'D') {
            return 2;
        }
        if (s[1] == 'F') {
            return 1;
        }
    } 
    
    else {
        return 0;
    }
    
    return 0;
}

int dp_func(int idx, int status)
{
    int &result = dp[idx][status];
    if (result != -1) {
        return result;
    }
    
    if (idx == col_size * row_size && !status) {
        return 0;
    }
    
    if (idx >= col_size * row_size && status) {
        return -1e9;
    }
    
    result = 0;    // '0'으로 초기화
    result = max(result, dp_func(idx + 1, status >> 1));
    
    if (status & 1) {
        result = max(result, dp_func(idx + 1, status >> 1));
    } 
    
    else {
        if (idx % row_size != row_size - 1 && (status & 2) == 0) {
            string v;
            v.push_back(value[idx]);
            v.push_back(value[idx + 1]);
            result = max(result, dp_func(idx + 2, status >> 2) + calValue(v));
        }
        
        string v;
        v.push_back(value[idx]);
        v.push_back(value[idx + row_size]);
        result = max(result, dp_func(idx + 1, (status >> 1) | (1 << (row_size - 1))) + calValue(v));
    }
    
    return result;
}

int main() 
{
    scanf("%d %d", &col_size, &row_size);    // 세로사이즈, 가로사이즈 입력
    for (int i = 0; i < col_size; i++) {
        string tmp_value; 
        cin >> tmp_value;    // 두부의 등급 입력
        value += tmp_value;    // 입력한 등급 합산
    }
    
    memset(dp, -1, sizeof(dp));    // dp 사이즈 '-1'로 초기화
    printf("%d", dp_func(0, 0));    // 출력
    
    return 0;
}
