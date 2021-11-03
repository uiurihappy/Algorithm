#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int findElement(int* key, int k, int n);
int rFE(int* key, int k, int l, int r);

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
    return rFE(key, k, 0, n - 1);
}

int rFE(int* key, int k, int l, int r) {
    int mid = r;

    if (l > r) 
        return mid;

    mid = (l + r) / 2;

    if (key[mid] == k) 
        return mid;

    else if (key[mid] > k) 
        return rFE(key, k, l, mid - 1);
    
    else 
        return rFE(key, k, mid + 1, r);

}