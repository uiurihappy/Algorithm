#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 9
 5 3 9
 3 8 15
 8 0 2
 2 0 0
 15 0 0
 9 7 10
 7 12 0
 12 0 0
 10 0 0

 3
 RLL
 LL
 LR
*/

typedef struct tree {
	int elem;
	struct tree* left, * right;
}TREE;

//노드 초기화
TREE* getNode(int elem) {
	TREE* n;

	n = (TREE*)malloc(sizeof(TREE));

	n->left = NULL;
	n->right = NULL;
	n->elem = elem;

	return n;
}

//트리 탐색
TREE* search(TREE* PARENT, int parent) {
	TREE* left = NULL;
	TREE* right = NULL;

	//만약 트리 노드가 NULL인 경우
	if (PARENT == NULL) {
		return NULL;
	}

	//root 원소 일치 시 트리 반환 
	if (PARENT->elem == parent) {
		return PARENT;
	}
	//좌 우측 트리
	left = search(PARENT->left, parent);
	right = search(PARENT->right, parent);
	
	//좌우측 NULL일 경우 반대쪽 반환
	if (left == NULL) {
		return right;
	}
	else {
		return left;
	}
}

//자식 추가
void addNode(TREE* root, int el, int le, int ri) {
	TREE* l = NULL, * r = NULL, *parent = NULL;

	//-1 이하
	if (root->elem <= -1) {
		//최상단 루트
		root->elem = el;
		parent = root;
	}
	else {
		//재탐색
		parent = search(root, el);
	}
	
	if (le != 0) {
		//초기화
		l = getNode(le);
		//좌측 트리 구성
		parent->left = l;
	}
	if (ri != 0) {
		//초기화
		r = getNode(ri);
		//우측 트리 구성
		parent->right = r;
	}
}

//출력
void printChild(TREE* parent, char op[]) {
	int i;

	printf(" %d", parent->elem);

	//L기준으로 L이 아니면 Right 출력
	for (i = 0; i < strlen(op); i++) {
		if (op[i] == 'L')
			parent = parent->left;
		else 
			parent = parent->right;

		printf(" %d", parent->elem);
	}

	printf("\n");
}

int main() {
	//초기화
	TREE *root = getNode(-1);
	//연산자
	char op[101] = { 0 };
	int n, i;
	int el, le, ri;

	//트리 초기화
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &el, &le, &ri);

		addNode(root, el, le, ri);
	}

	//트리 탐색
	scanf("%d", &n); // 탐색 횟수
	getchar();

	for (i = 0; i < n; i++) {
		gets(op);
		printChild(root, op);
	}

	return 0;
}