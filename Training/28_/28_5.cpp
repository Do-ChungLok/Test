#include <stdio.h>
#include <cstdio>
#include <vector>

#define ARRAY_SIZE_MAX 100001

using namespace std;

int in[ARRAY_SIZE_MAX];         //inorder저장
int post[ARRAY_SIZE_MAX];       //postorder저장
int find_root[ARRAY_SIZE_MAX];    //inorder의 root 쉽게 찾기 위해 사용, 숫자에 대한 위치 저장

void find_preorder(int in_start, int in_end, int post_start, int post_end)
{
    if (in_start > in_end || post_start > post_end){
        return;
    }
    
    int root = post[post_end];    // 포스트오더 배열 제일 마지막 데이터는 루트
    int in_Rpos = find_root[root];    // 인오더에서 루트 위치 찾기
    
    printf("%d ", root);
    find_preorder(in_start, in_Rpos - 1, post_start, post_start + (in_Rpos -1 - in_start)); // 루트값 기준 왼쪽노드로 범위 설정 
    find_preorder(in_Rpos+1, in_end, post_start + (in_Rpos -1 - in_start) + 1, post_end - 1); // 루트값 기준 오른쪽노드로 범위 설정
}

int main() 
{
    int spot_num;    // 정점의 개수
    scanf("%d", &spot_num);    // 정점의 개수 입력
    
    for(int i = 0; i < spot_num; i++){
        scanf("%d", &in[i]);    // 인오더 입력
        find_root[in[i]] = i;   // 루트값의 위치를 찾기 위해 순서 설정
    }
    
    for(int i = 0; i < spot_num; i++){
        scanf("%d", &post[i]);    // 포스트오더 입력
    }
    
    find_preorder(0, spot_num-1, 0, spot_num-1);    // 인오더, 포스트오더의 초기 시작, 끝 데이터로 함수 호출
}
