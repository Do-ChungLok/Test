#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE_MAX 51

struct Word {     // 길이, 단어배열 구조체 선언
    int str_len; 
    char str[STR_SIZE_MAX]; 
};

int compare(const void* first_word, const void* second_word)
{
    Word* word1 = (Word*)first_word;
    Word* word2 = (Word*)second_word;
    
    if (word1->str_len > word2->str_len) {
        return 1;
    } else if (word1->str_len < word2->str_len) {
        return -1;
    } else if (word1->str_len == word2->str_len) {    // 두 단어 길이가 같을 경우  
        if(strcmp(word1->str, word2->str) < 0)    // 사전순으로 정렬
            return -1;
        else
            return 1;
    }
    return 0;
}

int main(void)
{ 
    int i, j, N;
    Word* list;
    
    scanf("%d", &N);
    
    //list = (Word*)calloc(N + 1, sizeof(Word));
	list = new Word[N+1];
    
    for (i = 0; i < N; i++){ 
        scanf("%s", list[i].str);     // 단어 입력
        list[i].str_len = strlen(list[i].str);
        
        for(j = 0; j < i; j++){        // 중복 제거 ????????????????????
            if(strcmp(list[i].str, list[j].str) == 0){
                i -= 1;
                N -= 1;
                break;
            }
        }
    }
    
    qsort(list, N, sizeof(list[0]), compare);     // 정렬
    
	printf("----- result \n");
    for (i = 0; i < N; i++){
        printf("%s\n", list[i].str); 
    }

	delete[] list;

    return 0; 
}

