#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

/*
* 해시 테이블 = 버켓 배열 + 해시 함수
* 성능: O(n) 최악시간, 그러나 O(1) 대기 시간
*/

int h(int x, int M);                        //해시 함수
void initBucketArray(int* bucket, int M);   //초기화
int insertItem(int* bucket, int M, int x);  //삽입
int findElement(int* bucket, int M, int x); //탐색

int main(void) {
    char order;
    int* bucket;
    int M, n, x;
    int cnt = 0;
    int find;

    scanf("%d %d", &M, &n);
    getchar();

    //init
    bucket = (int*)malloc(sizeof(int) * M);
    initBucketArray(bucket, M);

    while (1) {

        scanf("%c", &order);
        getchar();

        if (order == 'i') {
            scanf("%d", &x);
            getchar();

            if (cnt >= n) 
                continue;
            printf("%d\n", insertItem(bucket, M, x));
            cnt++;
        }
        else if (order == 's') {
            scanf("%d", &x);
            getchar();

            find = findElement(bucket, M, x);
            if (find == -1)//탐색 실패 
                printf("-1\n");
            else 
                printf("%d %d\n", find, x);         //탐색 값
        }
        //탈출
        else if (order == 'e') 
            break;
    }
    //메모리 해제
    free(bucket);
    return 0;
}

//해시 함수
int h(int x, int M) {
    return x % M;
}

//초기화
void initBucketArray(int* bucket, int M) {
    for (int i = 0; i < M; i++) 
        bucket[i] = 0;
}

int insertItem(int* bucket, int M, int x) {
    int v = h(x, M);

    while (bucket[v] != 0) { //충돌이 안날때까지
        //충돌
        printf("C");
        v = h(v + 1, M);
    }

    bucket[v] = x; //저장 성공

    return v;
}

int findElement(int* bucket, int M, int x) {
    for (int i = 0; i < M; i++) 
        if (bucket[i] == x) 
            return i;

    return -1;
}