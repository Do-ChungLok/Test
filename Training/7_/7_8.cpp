#include <stdio.h>
#include <string.h>

int main() {
    char input[101];
    int count;
    int before_len;
    int after_len;
    
    scanf("%s",input);
    before_len=strlen(input);
    after_len=strlen(input);
    
    for(int i=0; i<before_len; i++)
    {    
        if( input[i] == 'c' || input[i] =='s' || input[i] == 'z')    // 만약 c,s,z 다음에.. 
        {  
         if (input[i+1] == '=' || input[i+1] == '-') 
             after_len--;  // 다음 문자에 '=' , '-' 가 있다면 after_len 길이 -
        }
        
        else if ( input[i] == 'n' || input[i] =='l') //  같은 방식으로 n,l 다음에
        {  
          if (input[i+1] == 'j') 
              after_len--;  // 그리고 다음문자에 'j' 가 있다면 after_len 길이 -
        }
        
        else if (input[i] =='d')    // 문자에 d 가 있다면
        {  
          if( input[i+1] == '-')
              after_len--;  // 다음 문자에 - 가 있다면 after_len 길이 -
          else if (input[i+1] == 'z' && input[i+2] == '=') 
              after_len--;  // 만약 z 가 있고, 그 다음 문자에 = 가  있다면 after_len 길이 -
        }
    }
    printf("%d\n",after_len);
    
    return 0;
    
}
