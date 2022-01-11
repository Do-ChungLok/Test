#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Trie {
	bool isFinished;    // 단어의 끝인지 판단 여부
	map <char, Trie> child;    // 다음 글자를 담을 맵
};

void insert(Trie &node, string &word, int idx)
{

	if (idx == word.size()) {
		node.isFinished = true;
		return;
	}
    
	if (node.child.count(word[idx]) == 0) {
		node.child[word[idx]] = Trie();
		node.child[word[idx]].isFinished = false;
	}
    
	insert(node.child[word[idx]], word, idx + 1);
}

int input_Count(Trie &node, string &word, int idx)
{
	if (idx == word.size()) {
		return 0;
	}
    
    // node.child.size() > 1 : 자식(다음 문자)가 2개 이상일때, idx == 0 : 현재 루트의 위치할때
	else if (node.child.size() > 1 || idx == 0) {   
		return input_Count(node.child[word[idx]], word, idx + 1) + 1;    // 카운트 ++
	}
    
    // node.child.size() == 1 && node.isFinished == true : 현재 탐색한 단어보다 더 긴 단어를 찾을 예정 
    // && 현재 위치에서 끝난 단어가 있음
	else if (node.child.size() == 1 && node.isFinished == true) {
		return input_Count(node.child[word[idx]], word, idx + 1) + 1;
	}
    
	else    // 다음 인덱스 값으로
		return input_Count(node.child[word[idx]], word, idx + 1);
}

int main() 
{
	int case_num;    // 테스트 케이스 수 

	while (cin >> case_num) {    // 테스트 케이스 수 만큼 입력

		vector <string> words;
		int sum = 0;

		Trie trie;
        
		for (int i = 0; i < case_num; i++) {
			string word;
			cin >> word;    // 문자열 입력
            
			words.push_back(word);
			insert(trie, word, 0);    // 입력한 문자열, 초기 인덱스 값 0 초기화 한 후 함수 호출
		}
        
		for (int i = 0; i < words.size(); i++) {
			sum += input_Count(trie, words[i], 0);
		}
        
		cout << fixed;        // 소수점 2자리 까지 출력
		cout.precision(2);    // 소수점 2자리 까지 출력
		cout << double(sum)/words.size() << "\n";    // 출력
	}
    
    return 0;
}
