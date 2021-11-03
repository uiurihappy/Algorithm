#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
void selection(int* p, int n) {
    int min, temp;
    int i, j;

    for (i = n-1; i > 0; i--) {

        min = 0;
        for (j = 1; j <= i; j++) {
            if (p[min] > p[j])
                min = j;
        }

        //교환
        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
        /*
        * Debug
        for (int i = 0; i < n; i++)
            printf(" %d", p[i]);
        printf("\n");
        */
    }
}

void insertion(int* p, int n) {
    int t, temp;
    int i, j;

    for (int i = 1; i < n; i++) {
        //i = pass, t = save
        t = p[i];

        j = i - 1;
        while ((j >= 0) && (p[j] > t)) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = t;
        /*
        * Debug
        for (int i = 0; i < n; i++)
            printf(" %d", p[i]);
        printf("\n");
        */

    }
}

void reverse(int* p, int n) {
    int t, temp;
    int i, j;

    /*삽입 정렬*/
    for (i = 1; i < n; i++) {

        t = i;
        for (j = i - 1; j >= 0; j--) {
            if (p[t] < p[j]) {
                break;
            }

            //교환
            temp = p[t];
            p[t] = p[j];
            p[j] = temp;

            t = j;
        }
    }
}

int main(void) {
    int* A, * B;
    int n, num;
    int i, j;

    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    srand(time(NULL));
    QueryPerformanceFrequency(&ticksPerSec);

    scanf("%d", &n);

    A = (int*)malloc(sizeof(int) * n);
    B = (int*)malloc(sizeof(int) * n);

    /*난수 저장*/
    for (i = 0; i < n; i++) {
        num = rand();
        A[i] = num;
        B[i] = num;
    }

    /* A : 난수 데이터 정렬 */
    printf("A\n");
    QueryPerformanceCounter(&start);
    /*선택*/ selection(A, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("선택정렬 : %0.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    QueryPerformanceCounter(&start);
    /*삽입*/ 
    insertion(B, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("삽입정렬 : %0.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    /* B : 이미 정렬된 데이터를 정렬*/
    printf("B\n");
    QueryPerformanceCounter(&start);
    /*선택*/
    selection(A, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("선택정렬 : %0.12fs\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    QueryPerformanceCounter(&start);
    /*삽입*/
    insertion(B, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("삽입정렬 : %0.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));


    /* C : 역순으로 정렬된 데이터를 정렬 */
    reverse(A, n);
    reverse(B, n);

    printf("C\n");
    QueryPerformanceCounter(&start);
    /*선택*/
    selection(A, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("선택정렬 : %0.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    QueryPerformanceCounter(&start);
    /*삽입*/
    insertion(B, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("삽입정렬 : %0.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    return 0;
}

