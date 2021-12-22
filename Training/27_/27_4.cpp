#include <iostream>
#include <cstring>
#include <stdio.h>
 
#define ARRAY_SIZE_MAX 1001

using namespace std;
 
string first_char, second_char, LCS;    // 문자열 1, 2, LCS
int dp[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // ex) dp[1][2] : 첫번째 문자의 첫번째, 두번째 문자의 두번째 문자의 부분수열 길이
int len;    // LCS 길이

void LCS_func()
{
    memset(dp, 0, sizeof(dp));     // dp 배열을 모두 0으로 초기화
    
    // LCS표를 구하는 과정
    for(int row = 1; row <= first_char.size(); row++){
        for(int col = 1; col <= second_char.size(); col++){
            if(first_char[row-1] == second_char[col-1]){
                // 만약 같은 문자가 나오면 두 문자열에서 
                // 해당 두 문자를 비교하기 전의 LCS의 길이에 1을 더한다
                dp[row][col] = dp[row-1][col-1] + 1;
            }
            // 문자가 다르다면 first_char[row-1]까지의 문자열 + second_char[col] 까지의 문자열 간의 LCS값과
            // first_char[row]까지의 문자열 + second_char[col+1] 까지의 문자열 간의 LCS값 중 큰값을 저장
            else{
                dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
            }
        }
    }
    
    len = dp[first_char.size()][second_char.size()];    // LCS 길이 변수
    
    cout << len << "\n";    // LCS 길이 출력
    
    int f_idx = second_char.size();
    
    for(int row = first_char.size(); row >= 1; row--){
        for(int col = f_idx; col >= 1; col--){
            
            if(dp[row][col] == dp[row-1][col]){
                f_idx = col;    // 바로 위 dp값이 같으면 현재 열 값을 유지한다
                break;
            }
            else if(dp[row][col] == dp[row][col-1]) {
                continue;
            }
            
            else {
                LCS = first_char[row-1] + LCS;
            }
        }
    }
    
    cout << LCS;    // LCS 출력
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> first_char >> second_char;    // 첫번째, 두번째 문자열 입력
    
    LCS_func();    // LCS 찾는 함수 호출
    
    return 0;
}



