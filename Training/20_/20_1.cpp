#include <stdio.h>

#define ARRAY_SIZE_MAX 129

int paper_arr[ARRAY_SIZE_MAX][ARRAY_SIZE_MAX]; // 색종이 데이터 배열
int blue_count;    // 파란색 색종이 개수
int white_count;   // 하얀색 색종이 개수 

//배열 정보를 받아서 한변의 길이 & x 좌표 & y 좌표 이렇게 3개의 값으로 사분면 모두를 체크
void check(int length, int start_X, int start_Y)     // stsrt_X : 체크를 시작할 X 위치
{                                                    // start_Y : 체크를 시작할 Y 위치
    int target = paper_arr[start_X][start_Y]; 
    
    for(int x = start_X; x < start_X + length; x++) { 
        for(int y = start_Y; y < start_Y + length; y++) { 
            
            if(paper_arr[x][y] != target) {     // 다른색을 발견한 경우
                check(length/2, start_X, start_Y + length/2);     // 1사분면
                check(length/2, start_X, start_Y);               // 2사분면
                check(length/2, start_X + length/2, start_Y);    // 3사분면 
                check(length/2, start_X + length/2, start_Y + length/2); // 4사분면
             
                return; 
            } 
        } 
    } 
    
    if(target == 0) 
        white_count++;     // 하얀색 색종이 개수 ++
    
    else 
        blue_count++;      // 파란색 색종이 개수 ++
}


int main()
{
    int length; // 종이의 한 변의 길이

    scanf("%d", &length);    // 한 변의 길이 입력
    
    
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            scanf("%d", &paper_arr[i][j]);  // 색종이 데이터 배열 입력          
        }       
    }
    
    check(length, 0, 0);    // 한 변의 길이, 0, 0 에서 시작
    
    printf("%d\n%d", white_count, blue_count);    // 하얀색 색종이, 파란색 색종이 개수 출력
}
