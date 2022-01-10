#include <stdio.h>
#include <algorithm>

#define ARRAY_SIZE_MAX 1000
#define COLOR_SIZE_MAX 3
#define INF 1000000
using namespace std; 

int main()
{ 
    int house_num;    // 집의 수
    int result = INF; 
    int house[ARRAY_SIZE_MAX][COLOR_SIZE_MAX] = { }; 
    int arr[ARRAY_SIZE_MAX][COLOR_SIZE_MAX] = { };    // arr[i][j] : i 번 집을 j 색으로 칠했을 때, 1 ~ i 집을 칠하는 최소비용
    
    scanf("%d", &house_num);    // 집의 수 입력
    
    for (int i = 0; i < house_num; i++) {        
        for (int j = 0; j < COLOR_SIZE_MAX; j++) { 
            scanf("%d", &house[i][j]);    // 주어진 색깔 배열 입력 
        } 
    } 
    
    for (int j = 0; j < COLOR_SIZE_MAX; j++) { 
        arr[0][0] = INF;    // 다른 색은 고를 수 없게 초기화      
        arr[0][1] = INF;    // 다른 색은 고를 수 없게 초기화  
        arr[0][2] = INF;    // 다른 색은 고를 수 없게 초기화  
        arr[0][j] = house[0][j]; // 처음 초기값 초기화
        
        for (int i = 1; i < house_num; i++) {    // 초기값 다음차례부터 연산
            arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + house[i][0]; 
            arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + house[i][1]; 
            arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + house[i][2]; 
        } 
        
        for (int i = 0; i < COLOR_SIZE_MAX; i++) { 
            if (i == j) {    // 첫번째와 마지막 색깔이 같은경우
                continue;
            }
            
            result = min(result, arr[house_num-1][i]);    // 나머지 경우의 최소값 
        } 
    } 
    
    printf("%d\n", result);    // 출력
    
    return 0;
}


