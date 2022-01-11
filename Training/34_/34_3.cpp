#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector< int> get_pi(string pattern)
{
	int m = pattern.length();
	vector<int> pi(m); 

	pi[0] = 0;
    
	for (int i = 1, j = 0; i < m; i++) { 
		while (j > 0 && pattern[i] != pattern[j])    // i 인덱스의 값과 j 인덱스의 값이 일치하지 않으면
			j = pi[j - 1];    // j - 1 인덱스 값을 j에 넣음     
        
		if (pattern[i] == pattern[j])    // i 인덱스랑 j 인덱스의 값이 같다면
			pi[i] = ++j; 
	} 
	return pi;
}

int main()
{
	int length_size;    // 전광판의 크기
    scanf("%d", &length_size);    // 전광판의 크기 입력

	string ad;    // 광고판에 보이는 문자열
	cin >> ad;    // 광고판에 보이는 문자열 입력

	vector <int> pi = get_pi(ad);
    printf("%d", length_size - pi[length_size - 1]);    // 전광판의 길이 - 문자열에서 반복해서 나오는 가장 긴 문자열 길이가 결과값
        
    return 0;
}

