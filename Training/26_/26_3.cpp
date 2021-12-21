#include <stdio.h>
#include <iostream> 
#include <algorithm> 
#include <vector>

#define ARRAY_SIZE_MAX 100001 

using namespace std; 

int main()
{ 
    int sequence_num, part_sum; // 수열의 길이, 부분합
    int seq_arr[ARRAY_SIZE_MAX] = { };

    scanf("%d %d", &sequence_num, &part_sum);    // 수열의 길이, 부분합 입력
    
    vector <int> seq_vec(sequence_num);     // 수열값이 저장될 벡터
    
    for(int i = 0; i < sequence_num; i++){ 
        scanf("%d", &seq_arr[i]);    // 수열값들 임력
    }
    
    int left = 0;    // 수열의 맨 왼쪽 기준점
    int right = 0;   // 수열의 오른쪽 기준점(여기서는 left와 같은 위치에서 시작)
    int sum = seq_arr[0]; // 현재 가중치 합
    int length = sequence_num + 1;    // 길이
    
    while(left <= right && right < sequence_num){ 
 
        if (sum < part_sum){ 
            sum += seq_arr[++right];    // sum = seq_arr[0] + seq_arr[++right]
        } 
        
        else if (sum >= part_sum){
            length = min(length, right - left + 1);    // 현재 length값과 부분합의 길이(right - left +1)를 비교
            sum -= seq_arr[left++];    // sum에서 arr[left] 값 빼주고 오른쪽으로 한 칸 이동
        }
    }
    
    if (length == sequence_num + 1){    // 합 만드는 것이 불가능한 경우
        length = 0;
    } 

    printf("%d\n", length); // 길이 출력
    
    return 0;
}

