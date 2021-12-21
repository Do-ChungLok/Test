#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <climits>

using namespace std; 

int INF = INT_MAX;
int liquid_num, left_value, right_value; // 용액의 수, 정렬했을 때 특정 용액 값

int main()
{ 
    scanf("%d", &liquid_num);    // 용액의 수 입력
    
    vector <int> liq_vec(liquid_num);     // 용액값들이 저장될 벡터
    
    for(int i = 0; i < liquid_num; i++) 
        scanf("%d", &liq_vec[i]);    // 용액값들 임력
    
    sort(liq_vec.begin(), liq_vec.end());     // 용액 데이터 값 오름차순 정렬
    
    int left = 0;    // 수열의 맨 왼쪽 기준점     
    int right = liquid_num - 1;    // 수열의 맨 오른쪽 기준점 
    int result = INF; 
    
    while(left < right){ 
        int sum = liq_vec[left] + liq_vec[right];    // 왼쪽, 오른쪽 데이터 값들의 합
        
        if(abs(sum) < result){ 
            result = abs(sum); 
            left_value = liq_vec[left]; 
            right_value = liq_vec[right]; 
        } 
        
        if(sum < 0) 
            left++;     // 정렬된 수열에서 왼쪽 기준점만 오른쪽으로 1칸 이동 
        
        else 
            right--;    // 정렬된 수열에서 오른쪽 기준점만 왼쪽으로 1칸 이동     
        } 
    
    printf("%d %d\n", left_value, right_value); 
}

