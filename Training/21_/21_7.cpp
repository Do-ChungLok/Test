#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> sequence_vec;    // 연속으로 증가된 원소들이 저장될 벡터

int Binary_Search_func(int num)    // 이진 탐색 함수
{
    int left = 0;
    int right = sequence_vec.size() - 1;
    
    while(left < right){
        int middle = (left + right) / 2;    // 입력 값보다 큰 첫 번째 값을 찾아야 함으로 >=으로 해서 right에 middle 포함
        
        if(sequence_vec[middle] >= num){
            right = middle;    
        } 
        
        else {    // 입력 값보다 작은 값은 볼 필요 없으니 middle+1
            left = middle + 1;            
        } 
    }
    
    return left;
}
 
 
int main(void)
{
    int sequence_size;    // 수열의 크기 변수
    scanf("%d", &sequence_size);    // 수열의 크기
    
    int num;    // 연속으로 증가하는 것을 표현하기 위한 index
    int idx = 0;
    
    for(int i = 0; i < sequence_size; i++){
        scanf("%d", &num);
 
        if (i == 0){    // 기준이 될 첫 번째 값 받기
            sequence_vec.push_back(num);
            continue;
        }

        if (sequence_vec[idx] < num){    // 저장된 원소 중에 가장 큰 값와 비교해서 입력된 값이 더 크다면, 벡터의 끝에 저장
            sequence_vec.push_back(num);
            idx++;
            
        } 
        
        else {    // 벡터의 어딘가와 비교해서 입력된 값으로 대체하기
            int pos = Binary_Search_func(num);
            sequence_vec[pos] = num;
        }
        
    }

    printf("%ld", sequence_vec.size());    // 연속된 값만 저장됨으로 벡터의 길이가 가장 긴 증가하는 부분 수열
}
