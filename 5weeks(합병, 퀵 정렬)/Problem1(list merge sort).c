#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
/*
8
73 65 48 31 29 20 8 3

3
4 9 1

O(n*logn)시간 수행
순차적 방식
*/
//단일 연결리스트 ADT
typedef struct node {
    int elem;
    struct node* next;
}NODE;

//getnode(노드 할당)
NODE* getNode() {
    NODE* node = (NODE*)malloc(sizeof(NODE));

    node->next = NULL;

    return node;
}
//insert(삽입)
NODE* insertList(NODE* T, int elem) {
    NODE* node = getNode();

    node->elem = elem;
    
    //트레일러에 저장
    T->next = node;

    return node;
}
//partition(분할)
void partition(NODE* L, int n, NODE** L1, NODE** L2) {
    NODE* p = L;
    *L1 = p;

    for (int i = 0; i < n - 1; i++)
        p = p->next;

    *L2 = p->next;
    p->next = NULL;
}
//merge(합병)
NODE* merge(NODE* L1, NODE* L2) {
    NODE* L;
    NODE* l1, * l2, * p;

    //isEmpty()
    if (L1 == NULL) 
        return L2;
    if (L2 == NULL) 
        return L1;

    l1 = L1; 
    l2 = L2;

    //init(초기화)
    if (l1->elem > l2->elem) { 
        L = l2;
        l2 = l2->next;
        //printf("%d \n", l1->elem);
    }
    // (l1->elem <= l2->elem)
    else {
        L = l1;
        l1 = l1->next;
        //printf("%d \n", l2->elem);
    }

    // 통치할 L을 저장
    p = L;

    while (l1 != NULL && l2 != NULL) { //isEmpty()
        if (l1->elem > l2->elem) {
            p->next = l2;
            l2 = l2->next;
        }
        else {
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }

    //null의 가능성을 봐야함
    while (l1 != NULL) {
        p->next = l1;
        l1 = l1->next;
        p = p->next;
    }

    while (l2 != NULL) {
        p->next = l2;
        l2 = l2->next;
        p = p->next;
    }

    return L;
}

NODE* mergeSort(NODE* L, int n) {
    NODE* L1 = NULL, * L2 = NULL;

    //크기가 1이면 그대로 반환
    if (n == 1) 
        return L;

    // n/2 앞을 L1, 뒤 노드시작을 L2로 Partition
    partition(L, n / 2, &L1, &L2);

    //재귀
    L1 = mergeSort(L1, n / 2);
    L2 = mergeSort(L2, n - n / 2);
    
    //통치
    L = merge(L1, L2);

    return L;
}

//출력
void printList(NODE* L) {
    NODE* p = L;

    while (p != NULL) {
        printf(" %d", p->elem);
        p = p->next;
    }
    printf("\n");
}

//메모리 해제
void freeNode(NODE** L) {
    NODE* p, * q;

    p = *L;

    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
}

int main(void) {
    //getNode
    NODE* L = getNode(), * T = L;
    int n, elem;
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &elem);

        if (i == 0) {
            L->elem = elem;
            continue;
        }
        //트레일러 노드 이용
        T = insertList(T, elem); 
    }

    L = mergeSort(L, n);

    printList(L);

    freeNode(&L);

    return 0;
}
