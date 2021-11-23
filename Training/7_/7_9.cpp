#include <stdio.h>

int main() {
    int N;
    char word[101];
    
    scanf("%d",&N);
    
    int count = N;

    for(int i=0; i<N; i++)
    {
        char first ='0';
        int alphabet[26]={0,};
        
        scanf("%s",word); 
        for(int j=0; word[j] != '\0'; j++)
        {
            if(first != word[j])
            {
                first = word[j];
                alphabet[word[j]-97] +=1;
            }
   
            if(alphabet[word[j]-97] ==2) 
                // 입력한 소문자를 -97 하여 0부터 시작하게 만든 후 배열에 저장, 배열에 중복일 경우 count -1 
            {
                count -=1;
                break;
            }
            
            else{}
        }
    }
    
    printf("%d",count);
    
    return 0;
    
}
