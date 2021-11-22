#include <stdio.h>


int main(void)
{
    char word[100]={0};
    
    scanf("%s",word);
    
    for(int i=97; i<=122; i++){
        int j = 0;
        while(word[j] != 0){
        	if(word[j] == (char)i)    // i를 문자로 변환 -> 아스키 코드에 해당하는 문자와 word[j]가 같은지
            		break;
            	j++;                  // 
    	}
    
    	if(word[j] == (char)i)
      	  printf("%d ",j);
   	 else
      	  printf("-1 ");
      	
    }
}



