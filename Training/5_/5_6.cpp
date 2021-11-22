#include <stdio.h>
#include <string.h>

int main(void) {
    
    int n;
    char ox[80];

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int sum = 0;
        int score = 1;
        
        scanf("%s", ox);
        for(int j=0; j<strlen(ox); j++) {
            if(ox[j] == 'O') {
                sum += score;
                score++;
            }
            if(ox[j] == 'X')  
                score = 1;
        } 
        printf("%d\n", sum);
    }
}

