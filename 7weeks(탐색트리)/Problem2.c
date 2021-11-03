#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    int height;             //높이 추가
    struct node* parent;    //루트 노드
    struct node* lChild;    //왼쪽 부트리
    struct node* rChild;    //오른쪽 부트리
}NODE;

//init
NODE* getNode() {
    NODE* node = (NODE*)malloc(sizeof(NODE));

    node->parent = NULL;
    node->lChild = NULL;
    node->rChild = NULL;

    return node;
}

int isRoot(NODE* node);
int isExternal(NODE* node);
NODE* expandExternal(NODE* node);
void insertItem(NODE** root, int k);
NODE* treeSearch(NODE* node, int k);
int findElement(NODE* node, int k);
void searchAndFixAfterInsertion(NODE** node, NODE* w);
int isBalanced(NODE* node);
int abs(int n);
int findMax(int n, int m);
int updateHeight(NODE* node);
NODE* restructure(NODE** root, NODE* x, NODE* y, NODE* z);
void printTree(NODE* node);
void freeNode(NODE* node);

int main(void) {
    NODE* root = getNode();

    char order;
    int key;
    int loop = 1;
    int elem;

    while (loop) {
        scanf("%c", &order);
        getchar();

        switch (order) {
        //삽입
        case 'i':
            scanf("%d", &key);
            getchar();

            insertItem(&root, key);
            break;
        //탐색
        case 's':
            scanf("%d", &key);
            getchar();

            elem = findElement(root, key);

            elem != -1 ? printf("%d\n", elem) : printf("X\n");
            break;
        //인쇄
        case 'p':
            printTree(root);
            printf("\n");
            break;
        //종료
        case 'q':
            freeNode(root);
            loop = 0;
            break;
        }
    }
    return 0;
}

int isRoot(NODE* node) {
    if (node->parent == NULL) 
        return 1;
    else 
        return 0;
}

int isExternal(NODE* node) {
    if (node->lChild == NULL && node->rChild == NULL) 
        return 1;
    else 
        return 0;
}

NODE* expandExternal(NODE* node) {
    NODE* left, * right;

    //init
    left = getNode();
    right = getNode();

    node->lChild = left;
    node->rChild = right;
    node->height = 1;

    left->parent = node;
    right->parent = node;

    return node;
}

void insertItem(NODE** root, int k) {
    NODE* w;

    w = treeSearch(*root, k);

    if (isExternal(w)) {
        w->key = k;
        w = expandExternal(w);
        searchAndFixAfterInsertion(root, w);
    }
}

NODE* treeSearch(NODE* root, int k) {
    NODE* node = root;

    if (isExternal(node)) 
        return node;

    if (k == node->key) 
        return node; // k == key(node)
    else if (k < node->key) 
        return treeSearch(node->lChild, k); // k < key(node)
    else 
        return treeSearch(node->rChild, k); // k > key(node)
}

int findElement(NODE* node, int k) {
    NODE* w;
    int e;
    w = treeSearch(node, k);

    if (isExternal(w)) 
        return -1;
    else {
        e = w->key;
        return e;
    }
}

//의사코드 안보고 쓸 수 있도록 암기!
void searchAndFixAfterInsertion(NODE** node, NODE* w) {
    NODE* x, * y, * z;
    z = w;

    w->lChild->height = 0;
    w->rChild->height = 0;
    w->height = 1;

    //root면 return
    if (isRoot(z))
        return;

    //w에서 루트로 향해 올라가다가 처음 만나는 불균형 노드 저장
    z = z->parent;

    while (updateHeight(z) && isBalanced(z)) {
        if (isRoot(z)) 
            return;
        z = z->parent;
    }

    
    //루트에 다다를 때까지 불균형 노드가 없다면 return
    if (isBalanced(z)) 
        return;

    //z의 높은 자식을 y로 설정
    if (z->lChild->height > z->rChild->height) 
        y = z->lChild;
    else 
        y = z->rChild;

    //y의 높은 자식을 x로 설정
    if (y->lChild->height > y->rChild->height) 
        x = y->lChild;
    else 
        x = y->rChild;

    //개조
    restructure(node, x, y, z);
}

int isBalanced(NODE* node) {
    NODE* left, * right;

    left = node->lChild;
    right = node->rChild;

    return abs(left->height - right->height) < 2;
}

int abs(int n) {
    if (n < 0) 
        return -1 * n;
    return n;
}

int findMax(int n, int m) {
    if (n > m) 
        return n;
    return m;
}

int updateHeight(NODE* node) {
    int h;
    NODE* left, * right;

    left = node->lChild;
    right = node->rChild;

    h = findMax(left->height, right->height) + 1;

    if (h != node->height) {
        node->height = h;
        return 1;
    }

    else return 0;
}

//개조
NODE* restructure(NODE** root, NODE* x, NODE* y, NODE* z) {
    NODE* a, * b, * c;
    NODE* T0, * T1, * T2, * T3;

    if (z->key < y->key && y->key < x->key) { //key(z) < key(y) < key(x)
        a = z; b = y; c = x;
        T0 = a->lChild; 
        T1 = b->lChild; 
        T2 = c->lChild; 
        T3 = c->rChild;
    }
    else if (x->key < y->key && y->key < z->key) { //key(x) < key(y) < key(z)
        a = x; b = y; c = z;
        T0 = a->lChild; 
        T1 = a->rChild; 
        T2 = b->rChild; 
        T3 = c->rChild;
    }
    else if (z->key < x->key && x->key < y->key) { //key(z) < key(x) < key(y)
        a = z; b = x; c = y;
        T0 = a->lChild; 
        T1 = b->lChild; 
        T2 = b->rChild; 
        T3 = c->rChild;
    }
    else { //key(y) < key(x) < key(z)
        a = y; b = x; c = z;
        T0 = a->lChild; 
        T1 = b->lChild; 
        T2 = b->rChild; 
        T3 = c->rChild;
    }

    if (isRoot(z)) {
        *root = b;
        b->parent = NULL;
    }
    else if (z->parent->lChild == z) {
        z->parent->lChild = b;
        b->parent = z->parent;
    }
    else { //z.parent.right == z
        z->parent->rChild = b;
        b->parent = z->parent;
    }

    a->lChild = T0;
    T0->parent = a;
    a->rChild = T1;
    T1->parent = a;
    updateHeight(a);

    c->lChild = T2;
    T2->parent = c;
    c->rChild = T3;
    T3->parent = c;
    updateHeight(c);

    b->lChild = a;
    a->parent = b;
    b->rChild = c;
    c->parent = b;
    updateHeight(b);

    return b;
}

//문제없음

void printTree(NODE* node) {
    if (isExternal(node)) 
        return;

    printf(" %d", node->key);

    printTree(node->lChild);
    printTree(node->rChild);
}

void freeNode(NODE* node) {
    if (node == NULL) 
        return;

    freeNode(node->lChild);
    freeNode(node->rChild);

    free(node);
}
