#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15
int count = 0;
int n;
int board[MAX_SIZE];

int promising(int num) {    // 퀸 위치 판별 함수

	// 같은 열이면 안되고, 대각선상에 있어서도 안됨
	for (int i = 0; i < num; i++) {
		if (board[num] == board[i] || num - i == abs(board[num] - board[i])) {
			return 0;
		}
	}
	return 1;
}

void n_queen(int num) {

	// num이 마지막 행까지 수행하고 여기까지 오면, 찾기 완료
	if (num == n) {
		count++;
		return;
	}

	for (int i = 0; i < n; i++) {
		board[num] = i;         // num번째 행, i번째 열에 queen을 위치시킴.	
		                        // 이후 그 행에 둔 것이 적절한지 판단.
		if (promising(num)) {   // 그 자리에 두어도 괜찮았다면,
			n_queen(num + 1);    // 그 다음 행에 대해 퀸을 놓는 것을 시도
		}
	}
}

int main() {

	scanf("%d", &n);
	n_queen(0);        
	printf("%d", count);
    //0을 처음에 선언하는 이유는 0을 제외한 (1~N,1~N)의 범위를 탐색하기 위해.
}
