 #pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

/*
* 해시 테이블 = 버켓 배열 + 해시 함수
* 성능: O(n) 최악시간, 그러나 O(1) 대기 시간
*/

int h(int x, int M);                                //첫 번째 해시 함수
int hPrime(int x, int q);                           //두 번째 해시 함수
void initBucketArray(int* bucket, int M);           //초기회
int insertItem(int* bucket, int M, int x, int q);   //삽입
int findElement(int* bucket, int M, int x);         //탐색
void printTable(int* bucket, int M);                //출력

int main(void) {
    char order;
    int* bucket;
    int M, n, q, x;
    int cnt = 0;
    int find;

    scanf("%d %d %d", &M, &n, &q);
    getchar();

    bucket = (int*)malloc(sizeof(int) * M);
    initBucketArray(bucket, M);

    while (1) {
        scanf("%c", &order);
        getchar();

        //삽입
        if (order == 'i') {
            scanf("%d", &x);
            getchar();

            if (cnt >= n) 
                continue;
            printf("%d\n", insertItem(bucket, M, x, q));
            cnt++;
        }
        //탐색
        else if (order == 's') {
            scanf("%d", &x);
            getchar();

            find = findElement(bucket, M, x);
            if (find == -1) printf("%d\n", -1);
            else printf("%d %d\n", find, x);
        }

        //테이블 출력
        else if (order == 'p') {
            printTable(bucket, M);
        }
        //한 번 출력 후 탈출
        else if (order == 'e') {
            printTable(bucket, M);
            //동시에 메모리 해제
            free(bucket);
            break;
        }
    }

    return 0;
}

//첫 번째 해시 함수
int h(int x, int M) {
    return x % M;
}

//두 번째 해시 함수
//최선의 결과를 위해 M은 서로소여야 한다.
int hPrime(int x, int q) {
    return q - (x % q);
}

void initBucketArray(int* bucket, int M) {
    for (int i = 0; i < M; i++) {
        bucket[i] = 0;
    }
}

int insertItem(int* bucket, int M, int x, int q) {
    int i = 1;
    int v = h(x, M);
    int hash = v;

    while (bucket[v] != 0) { //충돌이 안날때까지
        //충돌
        printf("C");
        //두 번째 함수로부터 얻은 셀로 이동
        //h(k) = (v+(1 * ( q - (x % q) ) ) ) % M;
        v = h(hash + (i * hPrime(x, q)), M);
        i++;
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

void printTable(int* bucket, int M) {
    for (int i = 0; i < M; i++)
        printf(" %d", bucket[i]);
    printf("\n");
}