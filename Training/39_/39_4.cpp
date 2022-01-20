#include <stdio.h>
#include <algorithm>

#define ARRAY_SIZE_MAX 200001

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

pair <int, int> arr[ARRAY_SIZE_MAX];
ll tree[2 * ARRAY_SIZE_MAX];
 
bool cmp(pair<int, int> x, pair<int, int> y)    // x, y좌표 오름차순 정렬     
{
    if (x.second == y.second) {
        return x.first < y.first;    // x 오름차순 정렬    
    }
    
    else {
        return x.second < y.second;  // y 오름차순 정렬         
    }
}
 
void update(int idx, int val)    // 펜윅트리 i번째 인덱스에 val 추가     
{
    while (idx <= 2 * ARRAY_SIZE_MAX) { 
        tree[idx]+= val; 
        idx+= (idx & -idx); 
    }
}
 
ll sum(int idx) {    // 펜윅트리 합
    ll answer = 0;
    while (idx > 0) { 
        answer += tree[idx]; 
        idx -= (idx & -idx);
    }
    
    return answer;
}
 
int main()
{

    int star_num;    // 별의 개수 
    scanf("%d", &star_num);    // 별의 개수 입력

    for (int i = 0; i < star_num; i++) {
        int x_input, y_input;    // x, y 좌표

        scanf("%d %d", &x_input, &y_input);    // x, y 좌표 입력 
   
        arr[i] = { x_input + ARRAY_SIZE_MAX, y_input + ARRAY_SIZE_MAX };    // 좌표가 1이상 되게
        update(x_input + ARRAY_SIZE_MAX, 1);    // x축 개수 업데이트
    }
    
    sort(arr, arr + star_num, cmp);    // 정렬
    ll result = 0;    // 초기값 '0'으로 초기화
    int prev = 1e9;
    
    for (int i = 0; i < star_num; i++) {
        if (arr[i].second != prev) {
            prev = arr[i].second;
            for (int j = i; arr[j].second == prev; j++) {    // y좌표가 같은 경우 (0으로 만들기)
                update(arr[j].first, -1);    // 0으로 만듦
            }
        }
        
        ll lsum = sum(arr[i].first - 1); // 왼쪽 개수
        ll rsum = sum(2 * ARRAY_SIZE_MAX) - sum(arr[i].first); // 오른쪽 개수
        result = (result + lsum * rsum) % MOD; // 결과값
    }
    
    printf("%lld\n", result);    // 출력
    
    return 0;
}

