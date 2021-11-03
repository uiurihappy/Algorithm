#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

//가장 첫 원소를 pivot으로 사용
int findPivot(int *arr, int l, int r) {
	return l;
}

//swap
void swapElement(int* arr, int a, int b) {
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int* inPlacePartition(int *arr, int l, int r, int k) {
	
	//pivot 저장
	int p = arr[k]; 

	swapElement(arr, k, r); 
	// l부터 하여
	int i = l;
	// r은 pivot이 위치하므로 r-1을 해줘 범위 지정.
	int j = r - 1; 

	while (i <= j) {
		while (i < r && arr[i] <= p)
			i++;
		while (j >= l && arr[j] >= p)
			j--;
		if (i < j)
			swapElement(arr, i, j);
	}
	//i와 j가 엇갈릴 경우
	// pivot 제자리로 위치하기 위해 swap
	swapElement(arr, i, r); 

	return i;
}

//퀵 정렬
void inPlaceQuickSort(int *arr, int l, int r) {
	if (l >= r)
		return;
	int k = findPivot(arr, l, r);
	int j = inPlacePartition(arr, l, r, k);
	
	inPlaceQuickSort(arr, l, j - 1);
	inPlaceQuickSort(arr, j + 1, r);
}

int main() {
	int n, * arr, i, number;
	//배열 초기화
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	//퀵 정렬
	inPlaceQuickSort(arr, 0, n - 1);

	for (i = 0; i < n; i++)
		printf(" %d", arr[i]);
	
	free(arr);
}
