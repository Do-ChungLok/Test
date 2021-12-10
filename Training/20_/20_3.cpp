#include <stdio.h>

int result[3];
int paper[2188][2188];    // 1 <= N <= 3^7  (3^7 = 2187)

// 단위 종이 내 모든 칸들의 값이 같은지 아닌지 판단하는 함수
bool check(int row, int col, int size) {
	
    int start_point = paper[row][col];    // 초기값을 배열에 넣어 시작점을 만듬
    
	for (int x = row; x < row + size; x++) {
		for (int y = col; y < col + size; y++) {
			if (start_point != paper[x][y]){    // 초기 배열값과 현재의 값이 다른 경우 분할 진행
                
				return 0;
            }
		}
	}
	return 1;
}

void divide_9(int row, int col, int size) {    // 9분할 실행 함수

	if (check(row, col, size)) {    // 지금 단위 종이 내 모든 칸들의 값이 같을 경우
		result[paper[row][col]]++;
	}
	else {
		
		int new_size = size / 3; // 새로운 단위사이즈를 만듬 
		                         // ex) 초기 size 27이었다면 다음 단위 정사각형의 size는 9
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				divide_9(row + new_size * x, col + new_size * y, new_size);
			}
		}
	}
}


int main() {

	int size_arr;    // 행렬 한 변의 크기
	scanf("%d", &size_arr);    // 행렬 한 변의 크기 입력

	for (int i = 0; i < size_arr; i++) {
		for (int j = 0; j < size_arr; j++) {

			int input;    // 정수
			scanf("%d", &input);    // 행렬에 정수 입력
			input++; // -1,0,1 을 각각 0,1,2로 표현		
			paper[i][j] = input;
		}
	}
	divide_9(0, 0, size_arr);
    
	printf("%d\n%d\n%d", result[0], result[1], result[2]);

}
