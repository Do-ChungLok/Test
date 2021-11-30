#include <stdio.h>
#include <stdlib.h>

typedef struct{    // 나이, 이름, 가입순서 구조체 선언
    int age;
    char name[101];
    int join_order;
} member;

int compare(const void* first_person, const void* second_person){
    member* person1 = (member*)first_person;
    member* person2 = (member*)second_person;
    
    if(person1->age > person2->age){
        return 1;
    }
    
    else if(person1->age < person2->age){
        return -1;
    }
    
    else if(person1->age == person2->age){               // 나이가 같을 경우
        if(person1->join_order < person2->join_order)    // 가입순서로 정렬
            return -1;
        else
            return 1;
    }
    return 0;
}

int main(){
    int N;
    scanf("%d", &N);
    
    member* list;
    list = (member*)malloc(N * sizeof(member));
    
    for(int i=0; i<N; i++){
        scanf("%d %s", &list[i].age, list[i].name);
        list[i].join_order = i;
    }
    
    qsort(list, N, sizeof(list[0]), compare);    // 정렬
    
    for(int i=0; i<N; i++){
        printf("%d %s\n", list[i].age, list[i].name);
    }
    
    return 0;
}
