#include <stdio.h>
#include <algorithm>

#define ARRAY_SIZE_MAX 100005

using namespace std;
using pii = pair<int, int>;

pii tree[4 * ARRAY_SIZE_MAX];
int loc[ARRAY_SIZE_MAX];

pii init(int node, int start, int end)    // 시작노드, start, end     
{
    if (start == end) {
        return tree[node] = {start, start};
    }
    
    else {
        int mid = (start + end) / 2;
        pii left = init(2 * node, start, mid);
        pii right = init(2 * node + 1, mid + 1, end);
        return tree[node] = {min(left.first, right.first), max(left.second, right.second)};
    }
}

    // 시작노드, start, end, qs, qe
    // start, end 는 가능한 최대범위 , qs, qe 는 찾고자하는 구간
pii query(int node, int start, int end, int qs, int qe)
{
    if (end < qs || qe < start) {    // 구하는 구간을 넘은 경우
        return {1e9, -1e9};
    }
    
    if (qs <= start && end <= qe) {    // 영역 범위 안에 전부 속한 경우
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    pii left = query(2 * node, start, mid, qs, qe);
    pii right = query(2 * node + 1, mid + 1, end, qs, qe);
    return {min(left.first, right.first), max(left.second, right.second)};
}

    // 시작노드, start, end, idx(찾아야 하는 데이터), num
pii update(int node, int start, int end, int idx, int num) 
{
    if (idx < start || idx > end) {    // 영역 밖에 있는 경우
        return tree[node];
    }
    
    if (start == end) {
        return tree[node] = {num, num};
    }
    
    else {
        int mid = (start + end) / 2;
        pii left = update(2 * node, start, mid, idx, num);
        pii right = update(2 * node + 1, mid + 1, end, idx, num);
        return tree[node] = {min(left.first, right.first), max(left.second, right.second)};
    }
}

int main()
{
    int case_num;    // 테스트 케이스 수
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    while (case_num--) {
        int dvd_num, event_num;    // dvd 수, 사건의 수 
        scanf("%d %d", &dvd_num, &event_num);    // dvd 수, 사건의 수 입력
        
        init(1, 0, dvd_num - 1);    // 세그먼트 트리 생성
        
        for (int i = 0; i < dvd_num; i++) {
            loc[i] = i;    // 데이터 입력  
        }
        
        while (event_num--) {
            int q, a, b; 
            scanf("%d %d %d", &q, &a, &b);    // 경우, 선반 A, B 입력
            
            if (q == 0) {
                update(1, 0, dvd_num - 1, loc[a], b);
                update(1, 0, dvd_num - 1, loc[b], a);
            swap(loc[a], loc[b]);    // a, b 위치 변경
                
            } 
            
            else {
                auto [m, M] = query(1, 0, dvd_num - 1, a, b);
                if (a == m && b == M) {    // 최소값, 최대값이 범위의 값과 같은 경우
                    printf("YES\n");    // 출력
                }
                
                else {
                    printf("NO\n");    // 출력
                }
                
            }    
        }
    }
    return 0;
}
