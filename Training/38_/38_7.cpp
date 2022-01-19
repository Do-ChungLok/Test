#include <stdio.h>

#define ARRAY_SIZE_MAX 100005

using ll = long long;

ll tree[4 * ARRAY_SIZE_MAX];
ll arr[ARRAY_SIZE_MAX];

void init(ll node, ll start, ll end)    // 시작노드, start, end 
{
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    ll mid = (start + end) / 2;
    init(2 * node, start, mid);
    init(2 * node + 1, mid + 1, end);
}

    // 시작노드, start, end, qs, qe
    // start, end 는 가능한 최대범위 , qs, qe 는 찾고자하는 구간
void update(ll node, ll start, ll end, ll qs, ll qe, ll num)
{
    if (end < qs || qe < start) {    // 구하는 구간을 넘은 경우
        return;
    }
    
    if (qs <= start && end <= qe) {    // 영역 범위 안에 전부 속한 경우
        tree[node] += num;
        return;
    }
    
    else {
        ll mid = (start + end) / 2;
        update(2 * node, start, mid, qs, qe, num);
        update(2 * node + 1, mid + 1, end, qs, qe, num);        
    }
  
}

    // 시작노드, start, end, idx(찾아야 하는 데이터), num
ll query(ll node, ll start, ll end, ll idx, ll ans) 
{
    if (end < idx || idx < start) {    // 영역 밖에 있는 경우
        return 0;
    }
    
    ans += tree[node];
    
    if (start == end) {
        return ans;
    }
    
    else {
        ll mid = (start + end) / 2; 
        return query(2 * node, start, mid, idx, ans) + query(2 * node + 1, mid + 1, end, idx, ans);        
    }

}

int main()
{
    ll sequence_size;    // 수열의 크기
    scanf("%lld", &sequence_size);    // 수열의 크기 입력
    
    for (ll i = 1; i <= sequence_size; i++) {
        scanf("%lld", &arr[i]);    // 데이터 입력
    }
    
    init(1, 0, 1e5);
    ll querry_num;    // 쿼리의 개수
    scanf("%lld", &querry_num);    // 쿼리의 개수 입력
    
    while (querry_num--) {
        ll input_querry;
        scanf("%lld", &input_querry);    // 쿼리 데이터 입력
        
        if (input_querry == 1) {
            ll qs, qe, num; 
            scanf("%lld %lld %lld", &qs, &qe, &num);    // 시작, 끝, 더하고자하는 수
            update(1, 0, 1e5, qs, qe, num);
        } 
        
        else {
            ll idx;
            scanf("%lld", &idx);    // 출력하고자 하는 데이터 입력
            printf("%lld\n", query(1, 0, 1e5, idx, 0));    // 출력
        }
    }    
    
    return 0;
}
