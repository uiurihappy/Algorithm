#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
	char elem;
	struct list* prev, * next;
}List;

void add(List li, int r, char e) {
	List* q = &li, * n;
	for (int i = 0; i < r; i++) {
		if (q->next == 0) {
			printf("invalid position\n");
			return;
		}
		q = q->next;
	}
	if (r == 0) {
		printf("invalid position\n");
		return;
	}
	//getnode()
	n = (List*)malloc(sizeof(List));

	n->prev = q->prev;
	(n->prev)->next = n;
	n->next = q;
	q->prev = n;
	n->elem = e;
}
void delete(List li, int r){
	List* q = &li;
	int i;
	for (i = 0; i < r; i++) {
		if (q->next == 0) { 
			printf("invalid position\n");
			return;
		}
		q = q->next;
	}
	if (q->next == 0 || r == 0) {
		printf("invalid position");
		return;
	}
	(q->next)->prev = q->prev;
	(q->prev)->next = q->next;
	free(q);
}

void get(List li, int r) {
	List* q = &li;
	int i;
	for (i = 0; i < r; i++) {
		if (q->next == 0) {  //순서 정보 유효하지 않은 경우
			printf("invalid position\n");
			return;
		}
		q = q->next;
	}
	if (q->next == 0 || r == 0) { //순서 정보 유효하지 않은 경우
		printf("invalid position\n");
		return;
	}

	printf("%c\n", q->elem);
}

void print(List li) {
	List* q;
	for (q = li.next; q->next; q = q->next) //출력
		printf("%c", q->elem);
	printf("\n");
}

int main() {
	int n, r;
	char com, e;
	List head, tail;

	//초기화
	tail.prev = &head;
	head.next = &tail;
	head.prev = 0;
	tail.next = 0;

	scanf("%d", &n);
	getchar();
	
	for (int i = 0; i < n; i++) {
		scanf("%c", &com);
		getchar();

		if (com == 'A') {
			scanf("%d", &r);
			getchar();
			scanf("%c", &e);
			getchar();
			add(head, r, e);
		}
		else if (com == 'D'){
			scanf("%d", &r);
			getchar();
			delete(head, r);
		}
		else if (com == 'G'){
			scanf("%d", &r);
			getchar();
			get(head, r);
		}
		else if (com == 'P') {
			print(head);
		}
	}
	return 0;
}