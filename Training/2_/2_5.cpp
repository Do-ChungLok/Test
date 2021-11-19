#include <stdio.h>
int main(){
    int h;
    int m;
    
    scanf("%d",&h);
    scanf("%d",&m);
    
    if(m<45){
        h = h-1;
        m = (m - 45)+ 60;
    
        if(h<0){	// '10'번째 코드에서 'h'가 0일때 h<0 조건에 해당 -> 즉 h = 0 일때 이 조건식이 성립 //
            h = 23;  
        }
    }
  
    else{
         m = m - 45;
    }
    printf("%d %d", h, m);
    
    return 0;
}

/*
2번째 방법
#include <stdio.h>
int main(){
    int h;
    int m;
    
    scanf("%d",&h);
    scanf("%d",&m);
    
    
    if(h != 0 ){
    
        if(m>=45)
            printf("%d %d\n",h-1, m-45);
        else
            printf("%d %d\n",h-1, m+60-45);
    }
        
    else{
        if(m>=45)
            printf("%d %d\n",h+24-1, m-45);
        else
            printf("%d %d\n",h+24-1, m+60-45);
    }
    return 0;
}
*/
