#include <stdio.h>

int main(){
    int T, k, n;
    int arr[15][15]={};    // 아파트 층, 호수는 <=14이기 때문에 15 크기 2중배열 선언
    
    for(int i=0; i<15; i++)    // 0층 i호는 i명 살음
    {
        arr[0][i]=i;
    }
    
    for(int i=1; i<15; i++)    // (i층 j호의 사람 수) = (i-1층 j호 사람수) + (i층 j-1호 사람수)
    {
        for(int j=1; j<15; j++)
        {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        scanf("%d %d", &k, &n);
        printf("%d\n",arr[k][n]);
    }
     
    return 0;
}
