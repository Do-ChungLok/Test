#include <stdio.h>
int main(){
    int a, b, c, d;
    int new_N=-1;
    int N, result, count=0;
    
    scanf("%d",&N);
    result = N;   
    while(new_N != result){ // 기존 입력한 'N'과 새로운 수 'new_N'가 다르면 종료
        a = N / 10; // N의 십의 자리 (0으로 나누고 몫)
        b = N % 10; // N의 일의 자리 (10으로 나누고 나머지)
        c = (a+b) % 10; // 새로운 수의 일의 자리
        d = (b*10); // 새로운 수의 십의 자리
        new_N = c+d; // 새로운 수 
        N = new_N;
        count++;
    }
    printf("%d",count); 
    return 0;   
}

/*
#include <stdio.h>
int main(){
    int N, new_N;
    int count=0;   
    scanf("%d",&N);
    new_N = N;   
    do{
        new_N = (((N %10) * 10) + (((N / 10) + ( N % 10 )) % 10));   
        count++;
    }
    while(new_N != N);
    printf("%d",count); 
    return 0;   
}
*/

/*
#include <iostream>

using namespace std;

int main(){
    int N, new_N;
    int count=0;   
    
    cin >> N;
    new_N = N;   
    do{
        new_N = (((N %10) * 10) + (((N / 10) + ( N % 10 )) % 10));   
        count++;
    }
    while(new_N != N);
    
    cout << count;
    return 0;   
}

*/

/*
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]){
    
    ios_base::sync_with_stdio(false);
    
    int N, new_N;
    int count=0;   
    cin >> N;
    
    new_N = N; 
    
    do{
        new_N = (N %10) * 10 + ((N / 10) + ( N % 10 )) % 10;   
        count++;
    } while(N != new_N);
    
    cout << count;
    return 0;   
}
*/

/*
#include <stdio.h>
int main(){
    int N, a, b, c, d, e, result;
    int count=0;
    
    scanf("%d",&N);
    result = N;   
    while(e != result){
        a = N / 10; // N의 십의 자리 (0으로 나누고 몫)
        b = N % 10; // N의 일의 자리 (10으로 나누고 나머지)
        c = (a+b) % 10; // 새로운 수의 일의 자리
        d = (b*10); // 새로운 수의 십의 자리
        e = c+d; // 새로운 수
        N = e;
        count++;
    }
    printf("%d",count); 
    return 0;   
}
*/
