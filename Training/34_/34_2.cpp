#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

string s;
vector<int>pi;

void init()
{
	s = "";
	pi.clear();
	cin >> s;
}

// 실패 함수 얻기
// pi : 접두사, 접미사 같은 최대 길이
vector<int> get_pi()
{
	int m = s.size();
	int j = 0;

	pi.resize(m, 0);

	for (int i = 1; i < m; i++) {
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) {
			j++;
			pi[i] = j;
		}
	}
	return pi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		init();
		if (s.size() == 1 && s[0] == '.')    // .인 경우 종료
			break;

		pi = get_pi();

		// ex) ababab => size = 6, pi[5]=4 => size - pi[5] = 2
		// 최댓값 = size / 2 = 3

		int size = s.size();
		int pattern_size = pi[size - 1];
		int answer = size / (size - pattern_size);

		if (size % (size - pattern_size) != 0) {
			cout << 1 << '\n';
		}
		else
			cout << answer << '\n';
	}
    
    return 0;
}
