#include <stdio.h>
int main(){
    int N,X;
    int arr[10000]; // 10,000보다 작아야 함
    
    scanf("%d %d",&N, &X);
    for(int i=1; i<=N; i++){
        scanf("%d", &arr[i]); // 'N'개의 갯수만큼 배열에 입력
    }
    
    for(int i=1; i<=N; i++){
        if(arr[i] < X){       // 배열에 있는 숫자가 처음 입력한 'X'보다 작으면 그 숫자를 출력
            printf("%d ", arr[i]);
        }
    }
    return 0;   
}
