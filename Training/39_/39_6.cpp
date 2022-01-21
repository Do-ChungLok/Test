#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>

#define ARRAY_SIZE_MAX 100001

using namespace std;

int people_num;  // 계란 던지는 사람 수
int days_num;    // 남은 일 수
int tsz;

struct Node 
{
    int left, right, val;    // l : 노드의 왼쪽 자식 인덱스, r : 노드의 오른쪽 자식 인덱스
    Node() : left(0), right(0), val(0) {};
    Node(int _left, int _right, int _val) : left(_left), right(_right), val(_val) {};
};

void init(vector <Node> &tree) 
{
    int sz = tsz / 2;
    for (int i = 1; i <= sz; ++i) {
        tree[i].left = i * 2; tree[i].right = i * 2 | 1;
    }
}

void update(vector<Node> &tree, int node, int start, int end, int val, int idx) 
{
    if (start != end) {
        int mid = (start + end) / 2;
        int n1 = tree[node].left;
        int n2 = tree[node].right;
        
        if (idx <= mid) {
            tree[node].left = tree.size();
            tree.push_back(Node(tree[n1].left, tree[n1].right, tree[n1].val + val));
            update(tree, tree[node].left, start, mid, val, idx);
        }
        
        else {
            tree[node].right = tree.size();
            tree.push_back(Node(tree[n2].left, tree[n2].right, tree[n2].val + val));
            update(tree, tree[node].right, mid + 1, end, val, idx);
        }
    }
}

int query(vector <Node> &tree, int node, int start, int end, int left, int right) 
{
    if (right < start || left > end) {
        return 0;
    }
    
    if (left <= start && end <= right) {
        return tree[node].val;
    }
    
    else {
        int mid = (start + end) / 2;
        int n1 = tree[node].left;
        int n2 = tree[node].right;
        return query(tree, n1, start, mid, left, right) + query(tree, n2, mid + 1, end, left, right);        
    }
}

int roots[ARRAY_SIZE_MAX + 4];
vector <Node> tree;
int main()
{
    tsz = 1;
    while (tsz < ARRAY_SIZE_MAX) {
        tsz *= 2;
    }
    
    tsz *= 2;
    int case_num;    // 테스트 케이스 수
    scanf("%d", &case_num);    // 테스트 케이스 수 입력
    
    while (case_num--) {
        scanf("%d %d", &people_num, &days_num);    // 사람 수, 남을 날짜 입력
        vector <vector <int>> yval(ARRAY_SIZE_MAX + 1);
        tree = vector <Node>(tsz);
        for (int i = 0; i < people_num; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);    // x, y 입력
            ++x; ++y;
            yval[x].push_back(y);
        }
        
        init(tree);
        roots[0] = 1;
        
        for (int i = 1; i <= ARRAY_SIZE_MAX; ++i) {
            roots[i] = tree.size();
            int pi = roots[i - 1];
            tree.push_back(Node(tree[pi].left, tree[pi].right, tree[pi].val));
            
            for (auto y : yval[i]) {
                tree[roots[i]].val += 1;
                update(tree, roots[i], 1, ARRAY_SIZE_MAX, 1, y);
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < days_num; ++i) {
            int left, right, b, t;
            scanf("%d %d %d %d", &left, &right, &b, &t);    // 데이터 입력
            ++right; ++b; ++t;
            ans += query(tree, roots[right], 1, ARRAY_SIZE_MAX, b, t) - query(tree, roots[left], 1, ARRAY_SIZE_MAX, b, t);
        }
        printf("%d\n", ans);    // 출력
    }
    return 0;
}
