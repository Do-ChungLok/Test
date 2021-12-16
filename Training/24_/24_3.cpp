#include <stdio.h>
#include<algorithm>

#define ARRAY_SIZE_MAX 26

int house_arr[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];      // 간선이 연결하는 두 정점의 배열
int house_arr2[ARRAY_SIZE_MAX * ARRAY_SIZE_MAX];    // 단지내 집의 수 배열
int num = 0;

using namespace std;

void dfs(int x, int y)
{
	house_arr[y][x] = 0;
	if (house_arr[y][x+1] == 1)    // 오른쪽 데이터 값이 1인 경우
		dfs(x + 1, y);
	if (house_arr[y][x - 1] == 1)  // 왼쪽 데이터 값이 1인 경우
		dfs(x - 1, y);
	if (house_arr[y+1][x] == 1)    // 위쪽 데이터 값이 1인 경우
		dfs(x, y + 1);
	if (house_arr[y-1][x] == 1)    // 아래쪽 데이터 값이 1인 경우
		dfs(x, y - 1);
    
	house_arr2[num]++;    // 단지내 집의 수++
}

int main(void)
{
	int map_size, count=0;    // 지도의 크기
	scanf("%d", &map_size);    // 지도의 크기 입력 
    
	for (int i = 0; i < map_size; i++){
		for (int j = 0; j < map_size; j++){
			scanf("%1d", &house_arr[j][i]);    // 단지 입력
		}
	}
	for (int i = 0; i < map_size; i++){
		for (int j = 0; j < map_size; j++){
			if (house_arr[i][j] == 1){    // 데이터값이 1인경우
				dfs(j, i);
				count++;    // 총 단지수++
				num++;
			}
		}
	}
    
	printf("%d\n", count);    // 총 단지수 출력
    
	sort(house_arr2, house_arr2 + count);
    
	for (int k = 0; k < count; k++){
		printf("%d\n", house_arr2[k]);    // 단지내 집의 수 출력
	}
}
