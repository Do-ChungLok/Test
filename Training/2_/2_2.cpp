#include <stdio.h>
 
int main(int argc, char const *argv[])
{
    int score;
    scanf("%d", &score);
    
    if(score >= 90)
        printf("A");
    else if(score >= 80)
        printf("B");
    else if(score >= 70)
        printf("C");
    else if(score >= 60)
        printf("D");
    else    
        printf("F");
    return 0;
}


/*
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int score;
    scanf("%d", &score);
    
    if(90 <= score && score <= 100)
        printf("A");
    else if(80 <= score && score <= 89)
        printf("B");
    else if(70 <= score && score <= 79)
        printf("C");
    else if(60 <= score && score <= 69)
        printf("D");
    else    
        printf("F");
    return 0;
}

*/
