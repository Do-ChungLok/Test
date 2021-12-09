#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
	int case_num;    // 케이스 수
	int docu_num, curious_num;    // 문서 수, 궁금한 문서 순서
	int importance;    // 문서의 우선순위
	int count;    // 인쇄 순서

	scanf("%d", &case_num);    // 케이스 수 입력

	for (int i = 0; i < case_num; i++) {
		count = 0;
		scanf("%d %d", &docu_num, &curious_num);    // 문서 수, 궁금한 문서 순서 입력 ( 0부터 시작 )
		
		priority_queue<int> pq; // 우선순위 큐, 내림차순 정렬해야 pop할 때 높은게 출력
		queue<pair<int, int>> q;

		for (int j = 0; j < docu_num; j++) {
			scanf("%d", &importance);    // 문서의 우선순위 입력
			q.push({ j, importance });
			pq.push(importance);
		}

		while (!q.empty()) {
			// 위치값과, 우선순위 값을 가져온 뒤 pop 실행
			int location = q.front().first;
			int value = q.front().second;
			q.pop();
            
			// 값 비교
			if (pq.top() == value) {    // 우선순위 큐에서 맨 위에 값과 value가 같을경우
				pq.pop();               // pop 해주고 count 증가
				++count;
				if (curious_num == location) {   // 궁금한 문서 순서와 lacation이 같은 경우
					printf("%d\n", count);       // count 출력 후 빠져나옴
					break;
				}
			}

			else{
                q.push({ location, value });
            } 
		}
	}

	return 0;
}
