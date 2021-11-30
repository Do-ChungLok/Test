#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> vec, back;    // 벡터 할당
    int N, input;
   
    scanf("%d", &N);    // 원소 개수 입력
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        vec.push_back(input);
        back.push_back(input);
    }
    
    
    sort(vec.begin(), vec.end());    // 오름차순 정렬
    vec.erase(unique(vec.begin(), vec.end()), vec.end());    // 중복 제거
    
    for(int i = 0; i < N; i++) {
        printf("%d ", lower_bound(vec.begin(), vec.end(), back[i]) - vec.begin());    // 입력순으로 입력값 위치 탐색
    }
    
}
