#include <stdio.h>
#include <vector>

#define ARRAY_SIZE_MAX 32002

using namespace std;

vector<int> front[ARRAY_SIZE_MAX];    // 앞에 있는 노드
int visited[ARRAY_SIZE_MAX] = { };    // 방문 여부 판단 배열

void DFS(int node) 
{
	visited[node] = true;    // 방문했다고 체크
    
	for (int i = 0; i < front[node].size(); i++) {
		if (visited[front[node][i]] == false) // 앞에 있는 노드 중 방문되지 않은 노드
			DFS(front[node][i]);
	}
    printf("%d ", node);
}

int main() 
{ 
	int student_num;    // 학생수
    int compare_num;    // 키 비교한 횟수
    scanf("%d %d", &student_num, &compare_num);    // 학생수, 키 비교환 횟수 입력

	for (int i = 0; i < compare_num; i++) {
		int stu_A, stu_B;
        scanf("%d %d", &stu_A, &stu_B);    // 학생 A, B 번호 입력
		front[stu_B].push_back(stu_A);
	}

	for (int i = 1; i <= student_num; i++) {
		if (visited[i] == false)    // 방문 안 했다면
			DFS(i);    // 다음 DFS 진행
	}
    
    printf("\n");
	return 0;
}
