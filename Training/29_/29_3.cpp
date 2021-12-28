#include <iostream> 
#include <string> 
#include <map> 
#include <algorithm> 
#include <cstring> 
#include <stdio.h>
#define ARRAY_SIZE_MAX 200200

using namespace std; 

int relation_num;    // 친구 관계의 수
int parent[ARRAY_SIZE_MAX], setSize[ARRAY_SIZE_MAX]; // 루트 찾는 함수 

int findParent(int node) 
{ 
    if (node == parent[node]){    // 자기자신이 부모노드라면 노드 반환     
        return node;    
    }
    
    else {
        return parent[node] = findParent(parent[node]);     // 현재 노드가 부모노드가 아닌 경우는 parent[node] 업데이트
    } 
}

//집합을 합치는 함수 
void union_func(int node1, int node2) 
{ 
    node1 = findParent(node1);     // node1이 속한 집합을 찾음 
    node2 = findParent(node2);     // node2가 속한 집합을 찾음 //같은 집합이 아닐 경우에만 합친다 
    
    if (node1 != node2) {          // 크기가 더 큰 집합으로 작은 집합이 들어감 
        if (setSize[node1] < setSize[node2]) { 
            swap(node1, node2); 
        } 
        
        parent[node2] = node1;     // node2 집합이 node1에 합쳐짐 
        setSize[node1] += setSize[node2]; // node1의 집합 크기가 커짐 
        setSize[node2] = 0;     // node2가 node1에 흡수되므로 
    } 
} 

int main(void) 
{ 
    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
       
    int case_num; 
    cin >> case_num;    // 테스트 케이스 수 입력
    
    for (int t = 0; t < case_num; t++) { 
        cin >> relation_num;    // 친구 관계의 수 입력
        
        for (int i = 0; i < ARRAY_SIZE_MAX; i++) { 
            parent[i] = i; 
            setSize[i] = 1; 
        } 
        
        map <string, int> name;    // map을 통해 사람 파악 -> 문자열을 노드 번호로 정리 
        int idx = 1;    // 이름에 대한 번호 변수
        
        for (int i = 0; i < relation_num; i++) { 
            string temp1, temp2; 
            cin >> temp1 >> temp2;    // 새로 나온 이름이라면 인덱스 부여 
            
            if (name.count(temp1) == 0) {    // 지금까지 입력받은 적이 없는 이름이라면 
                name[temp1] = idx++;         // 번호 부여
            } 
            
            if (name.count(temp2) == 0) {    // 지금까지 입력받은 적이 없는 이름이라면  
                name[temp2] = idx++;         // 번호 부여
            }    // 루트를 찾음 
            
            int temp1Parent = findParent(name[temp1]); 
            int temp2Parent = findParent(name[temp2]); // 같은 집합 내에 있다면 
            
            if (temp1Parent == temp2Parent) {
                cout << max(setSize[temp1Parent], setSize[temp2Parent]) << "\n"; 
            } // 다른 집합이라면 합친 뒤 
            
            else {
                union_func(temp1Parent, temp2Parent); 
                cout << max(setSize[temp1Parent], setSize[temp2Parent]) << "\n"; 
            } 
        } 
    } 
    
    return 0;
}

