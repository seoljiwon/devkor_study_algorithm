#include <iostream>
using namespace std;

// 노드 구조체는 data와 link로 구성
typedef struct Node {
    int data;
    Node * link;
}Node;

// 원형 리스트 구조체는 head 와 리스트 크기인 size로 구성
typedef struct CircularList {
    Node * head;
    int size;
}CircularList;

void createList(CircularList *list) { 
    list -> head = NULL;
    list -> size = 0;
}

// head를 newNode로 하여 노드를 추가하는 함수
void addNode(CircularList *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    

    if (list -> head == NULL){
        // head를 newNode로 하고, 자기 자신을 link로 연결
        list -> head = newNode;
        newNode -> link = list -> head;
    } else {
        // 기존 head가 가리키던 link를 newNode가 가리키고, 기존 head는 newNode를 가리키도록 함
        newNode -> link = list -> head -> link;
        list -> head -> link = newNode;
        // head를 newNode로 함
        list -> head = newNode;
    }
    
    list -> size ++;
}

// node -> link 노드를 지우는 함수
void removeNode(CircularList *list, Node *node){
    if (list -> size == 1){
        list -> head = NULL;
    } else {
        // head를 삭제해야 할 때
        if (node -> link == list -> head){
            list -> head = node -> link -> link;
        }

        // free(node -> link);
        node -> link = node -> link -> link;
    }

    list -> size --;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    CircularList list;

    createList(&list);

    int N, K;

    cin >> N >> K;

    // N이 7일 때 head부터 7, 1, 2, 3, 4, 5, 6 순으로 저장
    for (int i = 0; i < N; i++){
        addNode(&list, i + 1);
    }

    Node * node = list.head;

    cout << "<";

    while (N--){
        // node -> link가 삭제해야 할 노드
        for (int i = 0 ; i < K - 1 ; i++){
            node = node -> link;
        }

        cout << node -> link -> data;

        if (list.size > 1){
            cout << ", ";
        }

        removeNode(&list, node);
    }

    cout << ">";
    
}