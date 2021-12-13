#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
 
using namespace std;

// 세그먼트 알고리즘 이용
 
void init(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
    if (start == end)    // start와 end가 같으면 리프 노드. 이때 node에 start idx를 넣음.
        tree[node] = start; 
    
    else    // start와 end가 다르다면
    {
        int mid = (start + end) / 2;    // 가운데를 설정
        init(arr, tree, node * 2, start, mid);    // 가운데 기준 왼쪽
        init(arr, tree, node * 2 + 1, mid + 1, end);    // 가운데 기준 오른쪽
 
        if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])    // 각 구간에서 가장 높이가 낮은 것을 노드에 넣어줌
            tree[node] = tree[node * 2];
        else
            tree[node] = tree[node * 2 + 1];
    }
}
 
// 구간에서 가장 최소인 높이의 막대 구하기
int query(vector<int> &arr, vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return -1;
 
    if (left <= start && end <= right)
        return tree[node];
 
    int mid = (start + end) / 2;
    int m1 = query(arr, tree, node * 2, start, mid, left, right);
    int m2 = query(arr, tree, node * 2 + 1, mid + 1, end, left, right);
 
    if (m1 == -1)
        return m2;
 
    else if (m2 == -1)
        return m1;
 
    else
    {
        if (arr[m1] <= arr[m2])
            return m1;
        else
            return m2;
    }
}

// arr벡터(배열), tree벡터(배열), 노드번호, 노드 시작번호, 노드 끝번호
long long getMax(vector<int> &arr, vector<int> &tree, int start, int end)
{
    int n = arr.size();
    int m = query(arr, tree, 1, 0, n - 1, start, end);
 
    long long area = (long long)(end - start + 1)*(long long)arr[m];    // 넓이 계산
 
    if (start <= m - 1)    // 왼쪽 히스토그램이 존재 유무 판단
    {
        long long tmp = getMax(arr, tree, start, m - 1);
 
        if (area < tmp)
            area = tmp;
    }
 
    if (m + 1 <= end)    // 오른쪽 히스토그램이 존재 유무 판단
    {
        long long tmp = getMax(arr, tree, m + 1, end);
        if (area < tmp)
            area = tmp;
    }
 
    return area;    // 최대 히스토그램 넓이 반환
}
 
int main()
{
    while (1)
    {
        int case_num;    // 테스트 케이스 수
        scanf("%d", &case_num);    // 테스트 케이스 수 입력
 
        if (case_num == 0)
            break;
 
        vector<int> histo_high_arr(case_num);    // 히스토그램 높이 배열 벡터 선언
 
        for (int i = 0; i < case_num; i++)    // 히스토그램 높이 입력
            scanf("%d", &histo_high_arr[i]);
 
        int h = (int)(ceil(log2(case_num))+1e-9);    // 세그먼트 트리의 크기를 구하기 위해 올림함수 ceil 사용
        int tree_size = (1 << (h + 1));
 
        vector<int> tree(tree_size);
 
        init(histo_high_arr, tree, 1, 0, case_num - 1);    // 세그먼트 트리 형성
 
        printf("%lld\n", getMax(histo_high_arr, tree, 0, case_num - 1));
    }
 
    return 0;
}


