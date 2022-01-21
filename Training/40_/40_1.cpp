#include <iostream>
#include <string>
#include <algorithm>

#define ARRAY_SIZE_MAX 2501
#define INF 987654321

using namespace std;

string input;    // 문자열
int pelindrom[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];    // pelindrom[x][y] : x부터 y까지가 펠린드롬이면 true, 아니면 false
int dp[ARRAY_SIZE_MAX];    // dp[i] : i번째까지 펠린드롬 최소 개수

int main() 
{
	cin >> input;    // 문자열 입력
	input.insert(0, " ");    // 맨 앞에 '.' 추가 : 맨 처음문자까지 돌았을 때 펠린드롬이면 dp[0]=0으로 생각 
	int len = input.size();    // 입력한 문자열 길이
    
	for (int i = 1; i <= len; i++) {    // 1글자인 경우
        pelindrom[i][i] = true; 
    }
    
	for (int i = 1; i < len; i++) {    // 2글자인 경우
        if (input[i] == input[i + 1]) {
            pelindrom[i][i + 1] = true; 
        }
    }
    
	for (int i = 2; i < len; i++) {    // 3글자 이상인 경우
		for (int j = 1; j <= len - i; j++) {
			if (input[j] == input[i + j] && pelindrom[j + 1][j + i - 1]) {
                pelindrom[j][j + i] = true;
            }
        }
    }
    

	for (int i = 1; i < len; i++) {
		dp[i] = INF;
		for (int j = 1; j <= i; j++) {
			if (pelindrom[j][i]) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
		}
	}
	cout << dp[len-1] << endl;    // 결과 출력
    
    return 0;
}
	
