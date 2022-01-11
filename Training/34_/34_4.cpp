#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#define INTEGER_SIZE_MAX 360000

using namespace std;

vector <int> get_pi(vector<bool> pattern) {

	vector <int> pi(pattern.size(), 0);
	int j = 0;

	for (int i = 1; i < pattern.size(); i++) {
		while (j > 0 && pattern[i] != pattern[j]) {    // i 인덱스의 값과 j 인덱스의 값이 일치하지 않으면
			j = pi[j - 1];    // j - 1 인덱스 값을 j에 넣음     
		}
		if (pattern[i] == pattern[j]) {    // i 인덱스랑 j 인덱스의 값이 같다면
			pi[i] = ++j;
		}
	}
	return pi;
}

string kmp(vector<bool> text, vector<bool> pattern) {

	vector<int> pi = get_pi(pattern);
	int j = 0;

	for (int i = 0; i < text.size(); i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == pattern.size() - 1) {    // 일치하는 경우
				return "possible\n";
			}
			else {
				j++;
            }
		}
	}
	return "impossible\n";
}

int main()
{

	int clock_hands_num;    // 시계 바늘의 수
	vector<bool> clock1(INTEGER_SIZE_MAX * 2, 0); // 시계1을 두개 이어 붙임 -> text
	vector<bool> clock2(INTEGER_SIZE_MAX, 0);     // pattern -> 계1을 두 개 이어붙인 것을 전체 TEXT, 시계2를 Pattern으로 사용하여 해결

    scanf("%d", &clock_hands_num);    // 시계 바늘의 수 입력
	

	for (int i = 0; i < clock_hands_num; i++) {
		int num;
	
        scanf("%d", &num);    // 시계 방향 각도 입력        
		clock1[num] = clock1[INTEGER_SIZE_MAX + num] = 1;
	}
    
	for (int i = 0; i < clock_hands_num; i++) {
		int num;

        scanf("%d", &num);    // 시계 방향 각도 입력    
		clock2[num] = 1;
	}
    
	cout << kmp(clock1, clock2);    // 출력
    
    return 0;
}
