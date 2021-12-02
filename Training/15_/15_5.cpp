#include <stdio.h>

#define INPUT_ROW_SIZE_MAX 1001
#define INPUT_COL_SIZE_MAX 4
#define MAX 1000*1000

int Min(int num1, int num2)
{
    if (num1 < num2)
        return num1; 
    else
        return num2;
}

int main()
{
    int N;    // 집의 수
    
    int input_arr[INPUT_ROW_SIZE_MAX][INPUT_COL_SIZE_MAX];
    int color_arr[INPUT_ROW_SIZE_MAX][INPUT_COL_SIZE_MAX];
    
    scanf("%d", &N);    // 집의수 입력
    
    for (int i = 0; i < N; i++){
        for (int j = 1; j <= 3; j++)    // R, G, B -> 3개
            scanf("%d", &input_arr[i][j]);
    }
    
    color_arr[1][1] = input_arr[1][1];    // 첫번째 집 R
    color_arr[1][2] = input_arr[1][2];    // 첫번째 집 G
    color_arr[1][3] = input_arr[1][3];    // 첫번째 집 B
    
    for (int i = 2; i <= N; i++){
        color_arr[i][1] = Min(color_arr[i-1][2], color_arr[i-1][3]) + input_arr[i][1];
        color_arr[i][2] = Min(color_arr[i-1][1], color_arr[i-1][3]) + input_arr[i][2];
        color_arr[i][3] = Min(color_arr[i-1][1], color_arr[i-1][2]) + input_arr[i][3];
    }
    
    //printf("%d", Min(Min(color_arr[N][0], color_arr[N][1]), color_arr[N][2]));
    int min = MAX + 1;
	for (int i = 1; i <= 3; i++)
		if (color_arr[N][i] < min)
			min = color_arr[N][i];
	printf("%d", min);
    
    return 0;
    
}
