#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int findElement(int* key, int k, int n);

int main(void) {
    int* key;
    int n, k;
    int i;

    scanf("%d %d", &n, &k);
    key = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) 
        scanf("%d", &key[i]);

    printf(" %d", findElement(key, k, n));

    free(key);

    return 0;
}

int findElement(int* key, int k, int n) {
    int mid;
    int l = 0, r = n - 1;

    while (l <= r) {
        mid = (l + r) / 2;

        if (key[mid] == k)
            return mid;

        else if (key[mid] > k)
            r = mid - 1;

        else 
            l = mid + 1;
    }
}

