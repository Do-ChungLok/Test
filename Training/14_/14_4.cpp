#include <iostream>

#define MAX_SIZE 9

using namespace std;

int N, M;
int NM_array[MAX_SIZE];
bool NM_visit[MAX_SIZE];

void N_and_M(int num, int cnt) 
{

	if (cnt == M) 	
    {   
		for (int i = 0; i < M; i++)
			cout << NM_array[i] << " ";
		cout << "\n";
		
		return;
	}
	
	for (int i = num; i <= N; i++){	// 아직 자릿수가 다 채워지지 않은 경우 -> 'N'까지의 숫자 모두를 포함해야 함
			
            NM_visit[i] = true;	// 방문 처리
			NM_array[cnt] = i;	// 현재 자릿수를 저장
			N_and_M(i, cnt+1);	// 다음 경우의 수 탐색
            NM_visit[i] = false;	// 다음 경우의 수를 위해 현재 경우의 수가 끝났다면, 방문 취소 처리
	
		
	}
}

int main() {
	cin >> N >> M;
	N_and_M(1,0);	// 1번부터 시작
}

