#include <stdio.h>

#define ARRAY_SIZE_MAX 100000

int tree[4 * ARRAY_SIZE_MAX];

int init(int node, int start, int end)    // 시작노드, start, end   
{
    if (start == end) {
        return tree[node] = 1;
    }
    
    int mid = (start + end) / 2;
    return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
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
    int people_num, order;    // 사람 수, 몇 번째 변수
    scanf("%d %d", &people_num, &order);    // 사람 수, 몇 번째 변수 입력
    
    init(1, 1, people_num);    // 세그먼트 트리 생성
    int x = order;    // order번째 변수 저장
    
    printf("<");
    
    for (int i = 0; i < people_num - 1; i++) {
        printf("%d, ", query(1, 1, people_num, x));    // 출력
        x += order - 1;
        if (x % tree[1] == 0) {
            x = tree[1];
        }
        
        else {
            x %= tree[1]; 
        }
    }
    printf("%d", query(1, 1, people_num, x));    // 출력
    printf(">");
    
    // x = k라 할 때 처음엔 x번째 수를 제거하고 그다음은, x + k-1번째 수를 제거하고 
    // 다음은 x + 2*(k-1) 번째를 제거는 과정을 계속해서 반복
    // 이때 x + i(k - 1)이 남은 수의 개수보다 크다면 x + i(k-1) % (남은 수의 개수)
    
    return 0;
}
