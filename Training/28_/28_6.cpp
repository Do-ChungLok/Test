#include <stdio.h>
#include <vector>

#define ARRAY_SIZE_MAX 100001

using namespace std;

int input;    // 입력 데이터
int n;    // preodrer에서 배열 순서에 사용
int pre[ARRAY_SIZE_MAX];    //preorder저장

void find_post(int pre_start, int pre_end)
{
    int root = pre[pre_start];
    int idx = pre_start + 1;
    
    if (pre_start == pre_end){
        printf("%d\n", root);
        return;
    }
    
    if(pre_start > pre_end){
        return;
    }
    
    while(1){
        if (idx > pre_end || pre[idx] > root){    // idx가 루트보다 큰 구간을 찾음
            break;
        }
        idx++;
    }
    
    find_post(pre_start + 1, idx -1);    // idx값 기준으로 왼쪽 노드로 범위 설정
    find_post(idx, pre_end);             // idx값 기준으로 오른쪽 노드로 범우 ㅣ설정
    
    printf("%d\n", root);
}


int main()
{    
    n = 0;
    
    while ( scanf("%d", &input ) != -1 ){

        n++;    // 위치를 찾기 위해 순서 결정해주는 변수 ++
        pre[n] = input;
    }
    
    find_post(1, n);    // 함수 호출, 범위: 시작은 1부터 배열 끝 데이터까지
    
    return 0;
}
