#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define ARRAY_SIZE_MAX 1001

using namespace std;

int info_num;    // 먹이 정보의 개수
int each_info_num;    // 로봇 개미 한마리가 보내준 먹이 정보 개수
vector<string> foods[ARRAY_SIZE_MAX];    // 먹이 정보를 담을 벡터

// 자식 노드 담을 구조체
// map 컨테이너의 count : key값 존재하면 1, 없으면 0
// 입력의 순서대로 count==1 이면 거기에 자식 노드 붙힘
// 없으면 새 노드 붙힘
struct Node {    // 노드 구조체 선언
	map <string, Node> child;
};

void init()
{
	cin >> info_num;    // 먹이 정보 개수 입력
	for (int i = 0; i < info_num; i++) {
		cin >> each_info_num;    // 로봇 개미 한마리가 보내준 먹이 정보 개수
		for (int j = 0; j < each_info_num; j++) {
			string s;    // 먹이 문자열
			cin >> s;    // 먹이 정보 입력
			foods[i].push_back(s);
		}
	}
}

// vector v의 idx번째 입력을 node에 붙힘
// 해당 string이 없으면 새로 node에 붙힘
// 있으면 그 다음 string에 대해 검사
void insert(Node &node, vector <string> &v, int idx)
{
	if (idx == v.size())    // 리프 노드인 경우 (더 이상 붙힐 자식이 없음)
		return;

	map <string, Node>:: iterator iter;
	bool exit = false;
	for (iter = node.child.begin(); iter != node.child.end(); iter++) {
		if (iter->first == v[idx]) {
			exit = true;
			break;
		}
	}
    
	if (!exit) {
		node.child[v[idx]] = Node();
	}
	insert(node.child[v[idx]], v, idx + 1);
}

// 트라이에 저장된 데이터 출력
// map은 기본적으로 오름차순으로 정렬
void dfs(Node &node, int depth)
{
	map <string, Node>:: iterator iter;
    
	for (iter = node.child.begin(); iter != node.child.end(); iter++) {
		for (int idx = 0; idx < depth; idx++) {
			cout << "--";
		}
		cout << iter->first << '\n';
		dfs(iter->second, depth + 1);
	}
}

int main()
{
	init();
	Node root;

	for (int i = 0; i < info_num; i++) {    // 입력에 대해 트라이 만들기
		insert(root, foods[i], 0);
	}

	dfs(root, 0);    // 출력
    
    return 0;
}
