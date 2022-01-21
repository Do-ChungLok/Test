#include <stdio.h>
#include <vector>
#include <algorithm>
 
#define ARRAY_SIZE_MAX 400001
 
using namespace std;
using pii = pair <int, int>;
using ll = long long;
 
typedef struct vert 
{
    int x;
    pii y;
    bool start;
} vert;
 
int rectangle_num;    // 직사각형의 수
ll segtree[ARRAY_SIZE_MAX * 4];
ll cnt[ARRAY_SIZE_MAX * 4];
vector <vert> verts;
vector <int> ylist;
 
void update_range(int node, int start, int end, int l, int r, int val)
{
    if (l > end || r < start)    // 범위를 벗어난 경우 
    {
        return;   
    }
 
    if (l <= start && end <= r) {    // 완전히 포함되는 경우
      
        cnt[node] += val;    // 현재 구간이 우리가 갱신하려는 구간에 완전히 포함된다면 
                             // 현재 구간을 나타내는 구간의 cnt값을 증감시킨다는 것을 의미
    }
    else {     // 범위가 걸치는 경우
        int mid = (start + end) / 2;
        update_range(node * 2, start, mid, l, r, val);
        update_range(node * 2 + 1, mid + 1, end, l, r, val);
    }
 
        // 현재 노드가 나타내는 구간이 갱신하려는 구간에 완전히 포함될 때 segtree 값을 갱신하는 부분
    if (cnt[node]) {
        segtree[node] = (ll)ylist[end] - ylist[start - 1];    // 
    }
    
    else { // 걸치는 구간이라면 segtree의 양 자식 노드의 값을 더함
        if (start == end) {    // 리프 노드인경우 그 값은 0
            segtree[node] = 0;
        }
        
        else {
            segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
        }
    }
}
 
ll get_answer() 
{
    ll ret = 0;
    int diff_x = 0, diff_y;
    
    for (int i = 0; i < verts.size(); i++) {
        if (i > 0) {
            diff_x = verts[i].x - verts[i - 1].x;
            ret += segtree[1] * diff_x;
        }
        
        int val = verts[i].start == true ? 1 : -1;
        int y1_idx = lower_bound(ylist.begin(), ylist.end(), verts[i].y.first) - ylist.begin();
        int y2_idx = lower_bound(ylist.begin(), ylist.end(), verts[i].y.second) - ylist.begin();
        update_range(1, 1, ylist.size(), y1_idx + 1, y2_idx, val);
    }
 
    return ret;
}
 
vert create_vert(int x, int y1, int y2, bool start) 
{
    vert temp;
    temp.x = x;
    temp.y.first = y1; 
    temp.y.second = y2;
    temp.start = start;
    return temp;
}
 
bool cmp_vert(vert a, vert b)
{
    return a.x < b.x;
}
 
int main() 
{
    int x1, x2, y1, y2;    // x1, x2, y1, y2 좌표
    
    scanf("%d", &rectangle_num);    // 직사각형의 수 입력
 
    for (int i = 0; i < rectangle_num; i++) {
        scanf("%d %d %d %d", &x1, &x2, &y1, &y2);    // x1, x2, y1, y2 좌표 입력
        verts.push_back(create_vert(x1, y1 + 1, y2 + 1, 1));
        verts.push_back(create_vert(x2, y1 + 1, y2 + 1, 0));
        ylist.push_back(y1 + 1);
        ylist.push_back(y2 + 1);
    }
 
    sort(ylist.begin(), ylist.end());    // y좌표값 정렬
    ylist.erase(unique(ylist.begin(), ylist.end()), ylist.end());
    sort(verts.begin(), verts.end(), cmp_vert);    // 좌표 압축을 위한 중복 값 제거
    ll answer = get_answer();
    
    printf("%lld\n", answer);    // 출력
 
    return 0;
}
