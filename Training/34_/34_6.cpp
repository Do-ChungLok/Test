#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    int word_num, check_word_num;
    map <string, int> S;
    int check_count = 0;    // 집합S에 포함되는지 카운트 변수

    cin >> word_num >> check_word_num;    // 집합 S에 포함되어 있는 문자열 개수, 검사해야 하는 문자열 개수 입력

    //집합 S에 포함되는 문자열 word
    //word를 key 값으로 하는 value는 1로 저장.
    for (int i = 0; i < word_num; i++) {
        string word;

        cin >> word;    // 집합 S에 포함되어 있는 문자열 입력 
        S[word] = 1;    // word를 key 값으로 하는 value는 1로 저장
    }

    //M개의 문자열을 입력받는 word
    for (int i = 0; i < check_word_num; i++) {
        string word;

        cin >> word;    // 검사해야 하는 문자열 입력

        if (S[word] == 1) {    // word를 key 값으로 하는 요소 중에서 value가 1이면 집합 word에 포함되는 문자열
            check_count++;
        }
    }

    cout << check_count;

    return 0;
}
