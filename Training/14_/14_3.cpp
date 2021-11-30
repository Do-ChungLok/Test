#include <iostream>

#define MAX_SIZE 9

using namespace std;

int NM_array[MAX_SIZE];
bool NM_visit[MAX_SIZE];

void N_and_M(int num1, int num2, int now) {


	if (now > num2) {	// 만약 현재 호출한 횟수(now)가 출력할 자릿수(num2)보다 많다면 입력받은 자릿수만큼까지 저장된 배열을 출력
		
		for (int i = 1; i <= num2; i++)
			cout << NM_array[i] << " ";
		cout << "\n";
		
		return;
	}

	
	for (int i = 1; i <= num1; i++){	// 아직 자릿수가 다 채워지지 않은 경우 -> 'num1'까지의 숫자 모두를 포함해야 함
				
			NM_array[now] = i;	// 현재 자릿수를 저장
			NM_visit[i] = true;	// 방문 처리
			N_and_M(num1, num2, now + 1);	// 다음 경우의 수 탐색
			NM_visit[i] = false;	// 다음 경우의 수를 위해 현재 경우의 수가 끝났다면, 방문 취소 처리
		
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	N_and_M(N, M, 1);	// 1번부터 시작
}

