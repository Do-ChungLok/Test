#include <stdio.h>

#define ARRAY_SIZE_MAX 2000000

int tree[ARRAY_SIZE_MAX * 4];

void update(int node, int start, int end, int idx) 
{
    if (idx < start || end < idx) {
        return;
    }
    
    tree[node]++;
    
    if (start == end) {
        return;
    }
    
    else {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, idx);
        update(2 * node + 1, mid + 1, end, idx);        
    }
}

int query(int node, int start, int end, int k)    // k 번째 수
{
    tree[node]--;
    if (start == end) {
        return start;
    }
    
    // K 번째 수는 결국 왼쪽에 K개가 있으면 그 노드가 K번째 수이므로 위치의 수를 구할 수 있음
    // K가 왼쪽 노드의 수보다 클 경우 K - 왼쪽 노드의 개수를 다시 K로 하여 오른쪽 노드에서 탐색

    int mid = (start + end) / 2; 
    if (tree[2 * node] >= k) {
        return query(2 * node, start, mid, k);
    }
    
    else {
        return query(2 * node + 1, mid + 1, end, k - tree[2 * node]);
    }
}

int main()
{
    int querry_num;    // 쿼리의 수 
    scanf("%d", &querry_num);    // 쿼리의 수 입력
    
    while (querry_num--) {
        int mode, plus_input;    // 1 or 2 mode, 추가할 수
        scanf("%d %d", &mode, &plus_input);    // 1 or 2 mode, 추가할 수 입력
        
        if (mode == 1) {    // mode가 1인 경우
            update(1, 1, ARRAY_SIZE_MAX, plus_input);
        }
        
        else if (mode == 2) {    // mode가 2인 경우
            printf("%d\n", query(1, 1, ARRAY_SIZE_MAX, plus_input));    // 출력
        }
    }
    
    return 0;
}
