#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *num = (char*)malloc(sizeof(char));
    char temp;
    int length;
  
    gets(num);
    length = strlen(num);
    
    for(int i=0; i<length; i++){
        for(int j=i; j<length; j++){
        
            if(num[i] < num[j]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    
    puts(num);
    
    return 0;
}


/*
#include <stdio.h>
#include <string.h>

int main({
    char *num = (char*)malloc(sizeof(char));
    char temp;
    int length;
  
    gets(num);
    length = strlen(num);
    
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
        
            if(num[i] > num[j]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    
    puts(num);
    
    return 0;
}
*/
