#include <stdio.h>

#define ARRAY_SIZE_MAX 100000

int num_arr[ARRAY_SIZE_MAX];
int stacked_num[ARRAY_SIZE_MAX];

int Max(int num1, int num2)
{
    if (num1 > num2)
        return num1; 
    else
        return num2;
}

int main()
{
    int N;    // 포도주 잔의 개수

    scanf("%d", &N);    // 포도주 잔의 개수 입력
    
    for (int i = 1; i <=N; i++)
        scanf("%d", &num_arr[i]);
    
    stacked_num[1] = num_arr[1];    // 처음 잔의 포도주 양
    stacked_num[2] = num_arr[1] + num_arr[2];    // 두번째 잔까지 포도주 양
    
    for (int i = 3; i <=N; i++)
    {
        stacked_num[i] = Max(stacked_num[i - 2] + num_arr[i], Max(stacked_num[i - 3] + num_arr[i-1]+ num_arr[i], stacked_num[i - 1]));
    }
    //    ...i-2  i-1   i
    // 1) ... ●   ●   ○ : stacked_num[i - 1]
    // 2) ... ●   ○   ● : stacked_num[i - 2] + num_arr[i]
    // 3) ... ○   ●   ● : stacked_num[i - 3] + arr[i - 1] + arr[i]    
    
    printf("%d", stacked_num[N]);
}

