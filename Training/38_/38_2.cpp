#include <stdio.h>

#define ARRAY_SIZE_MAX 1000002

using ll = long long;

ll input[ARRAY_SIZE_MAX];
ll tree[4 * ARRAY_SIZE_MAX];

ll init(ll node, ll start, ll end)    // 시작노드, start, end
{
    if (start == end) {
        return tree[node] = input[start];
    }
    
    else {
        ll mid = (start + end) / 2;
        ll left = init(node * 2, start, mid);
        ll right = init(node * 2 + 1, mid + 1, end);
    
        return tree[node] = left + right;       
    }
}

    // 시작노드, start, end, left, right
    // start, end 는 가능한 최대범위 ,left, right 는 찾고자하는 구간
ll sum(ll node, ll start, ll end, ll left, ll right)
{
    if (start > right || end < left) {    // 구하는 구간을 넘은 경우
        return 0;
    }
    
    if (left <= start && end <= right) {    // 영역 범위 안에 전부 속한 경우
        return tree[node];
    }
    
    else {
        ll mid = (start + end) / 2;
    
        return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);        
    }
}

    // start, end, 시작노드, index(찾아야 하는 데이터), dif(변화량)
    // start, end 는 가능한 최대범위 ,left, right 는 찾고자하는 구간
void change_variable(ll start, ll end, ll node, ll index, ll dif) 
{
    if (index < start || index > end) {    // 영역 밖에 있는 경우
        return;
    }
    
    tree[node] += dif;
    
    if (start == end) {
        return;
    }
    
    else {
        ll mid = (start + end) / 2;
        change_variable(start, mid, node * 2, index, dif);
        change_variable(mid + 1, end, node * 2 + 1, index, dif);        
    }

}

int main() 
{
    ll input_num, change_num, sum_num;    // 수의 개수, 수 변경 횟수, 구간의 합을 구하는 횟수
    scanf("%lld %lld %lld", &input_num, &change_num, &sum_num);
    for (ll i = 1; i <= input_num; i++) {
        scanf("%lld", &input[i]);    // 데이터 입력
    }
    
    init(1, 1, input_num);    // 세그먼트 트리 생성
    
    for (ll i = 0; i < change_num + sum_num; i++) {
        ll a, b, c;    // 세개의 정수
        ll dif = 0;
        scanf("%lld %lld %lld", &a, &b, &c);    // 세개의 정수 입력
        
        if (a == 1) {    // a == 1인 경우
            dif = c - input[b];    // 변경하려는 숫자와 기존 숫자의 차이
            input[b] = c;    // 숫자 변경
            change_variable(1, input_num, 1, b, dif);
        } 
        
        else if (a == 2) {
            printf("%lld\n", sum(1, 1, input_num, b, c));    // a == 2인 경우 출력
        }
    }
    
    return 0;
}
