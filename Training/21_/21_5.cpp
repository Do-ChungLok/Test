#include <stdio.h>
#include <algorithm> 

using namespace std;

#define ARRAY_SIZE_MAX 1000001
 
int house_num;    // 집의 수
int share_num;    // 설치할 공유기의 수
int ans;          // 이진 탐색 함수에서 최종 반환값
int result;	  // 결과값

int house_location_arr[ARRAY_SIZE_MAX] = { };    // 집의 좌표 저장할 배열
 
int Binary_Search_func(int left, int right)    // 이진 탐색 함수
{
 
    while (left <= right){
 
        int middle = (left + right) / 2;
        int start_house = house_location_arr[0];
        int calculated_count = 1;    // 첫번째 집에는 공유기가 설치 되어야 하니까 '1'로 초기화
        
        for (int i = 0; i < house_num; i++){
            if (house_location_arr[i] - start_house >= middle){    
                start_house = house_location_arr[i];
                calculated_count++;
            }
        }
        
        if (calculated_count >= share_num){    // 계산된 공유기의 수 >= 설치할 공유기의 수
            ans = middle;
            left = middle + 1;    // 공유기 간의 간격을 늘림
        }
        
        else if (calculated_count < share_num){    // 계산된 공유기의 수 <= 설치할 공유기의 수
            right = middle - 1;    // 공유기 간의 간격을 줄임
        }    
    }
    return ans;
}
 
int main(void)
{   
    scanf("%d %d", &house_num, &share_num);    // 집의 수, 설치할 공유기의 수 입력
 
    for (int i = 0; i < house_num; i++){
        scanf("%d", &house_location_arr[i]);    // 집의 좌표 입력
    }
 
    sort(house_location_arr, house_location_arr + house_num);    // 좌표 오름차순 정렬
    
    result = Binary_Search_func(1, house_location_arr[house_num - 1]);
    
    printf("%d\n", result);    // 출력
 
    return 0;
}

