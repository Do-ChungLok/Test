#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE_MAX 1000

char charcter_arr1[ARRAY_SIZE_MAX], charcter_arr2[ARRAY_SIZE_MAX];
int str1, str2;
int LCS_arr[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX];

int Max(int num1, int num2)
    
{
    if (num1 > num2)
        return num1; 
    else
        return num2;
}

int comparison_func(int position1, int position2)     // position1 : 첫번째 수열의 비교할 문자 위치
{                                           // position2 : 두번째 수열의 비교할 문자 위치
    if (position1 == str1 || position2 == str2) 
        return 0;
    
    // 첫번째 수열의 position1의 위치와 두번째 수열 position2의 위치가 같다면 LCS +1 & 비교할 문자의 위치 한 칸 이동
    if (charcter_arr1[position1] == charcter_arr2[position2])
        return ( 1 + comparison_func(position1 + 1, position2 + 1) );
 
    int result = 0;
    
    if (LCS_arr[position1][position2] != -1) 
        return LCS_arr[position1][position2];
    
    // 첫번째 수열의 position1의 위치와 두번째 수열 position2의 위치가 일치 x : 두개의 문자열에 한 칸 이동하고 둘 중 큰 값 반환
    result = Max(comparison_func(position1 + 1, position2), comparison_func(position1, position2 + 1));
        return LCS_arr[position1][position2] = result;
}

int main() 
{
    scanf("%s %s", charcter_arr1, charcter_arr2);    // 문자열 두개 입력
    str1 = strlen(charcter_arr1); 
    str2 = strlen(charcter_arr2);
    memset(LCS_arr, -1, sizeof(int) * ARRAY_SIZE_MAX * ARRAY_SIZE_MAX);
    
    int result = comparison_func(0, 0);
    
    printf("%d\n", result);
}
