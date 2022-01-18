#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

#define ARRAY_SIZE_MAX 100001

using namespace std;

int input_num;    // 정수의 개수
int pair_num;     // 쌍의 개수
int input[ARRAY_SIZE_MAX];
vector <int> min_tree, max_tree;    // 최소, 최대 저장할 벡터

void init(int node, int start, int end)    // 시작노드, start, end
{
    if (start == end) {
        min_tree[node] = max_tree[node] = input[start]; 
        return;
    }
    
    else {
        int mid = (start + end) / 2;
        init(node * 2, start, mid );
        init(node * 2 + 1 , mid +1, end);
        
        min_tree[node] = min (min_tree[node * 2], min_tree[node * 2 + 1]); 
        max_tree[node] = max (max_tree[node * 2], max_tree[node * 2 + 1]);
        
        return;
    }
}

// a, b범위에따른 최소, 최댓값을 쌍으로 묶어서 리턴하는 함수
// 최솟값, 최댓값쌍을 리턴
// start, end 는 가능한 최대범위
// left, right 는 찾고자하는 구간
pair <int, int> findMinMAx(int node, int start, int end, int left, int right)
{
    if (start > right || end < left) {
        return make_pair(INT32_MAX, 0);    // return 됐을때 최소값으로 지정되면 안 되므로 INT32_MAX
    }
    
    else if (left <= start && end <= right) {
        return make_pair(min_tree[node], max_tree[node]);
    }
    
    else {
        pair <int, int> l, r;    // l : 왼쪽, r : 오른쪽
        int mid = (start + end) / 2;
        
        l = findMinMAx(node * 2, start, mid, left, right);
        r = findMinMAx(node * 2 + 1, mid + 1, end , left, right);
        
        return make_pair(min (l.first, r.first), max (l.second, r.second));
    }
}

int main()
{
    scanf("%d %d", &input_num, &pair_num);    // 수의 개수, 쌍의 개수 입력

    int h = (int)ceil(log2(input_num));        
    int tree_size = (1 << (1 + h));    // 트리 사이즈 설정

    min_tree = vector <int>(tree_size);
    max_tree = vector <int>(tree_size);

    for(int i = 1; i <= input_num ; i++)
        scanf("%d", &input[i]);    // 정수 입력

    init(1, 1, input_num);    // 세그먼트 트리 생성
    
    int left, right;
    pair <int, int> result;
    
    while (pair_num--) {
        scanf("%d %d", &left, &right);    // 쌍(왼쪽, 오른쪽) 입력
        result = findMinMAx(1, 1, input_num, left, right);
        printf("%d %d\n",result.first, result.second);    // 출력
    }
    
    return 0;
}
