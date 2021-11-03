#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
8
8 31 48 73 3 65 20 29
*/
int main() {
	int n, * p;
	int temp, minLoc = 0;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int) * n);

	//input
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for (int i = n - 1; i > 0; i--) {

		minLoc = 0;

		for (int j = 1; j <= i; j++) {
			if (p[minLoc] < p[j])
				minLoc = j;		// 더 큰 배열 위치변경
		}

		// swap
		temp = p[i];
		p[i] = p[minLoc];
		p[minLoc] = temp;

		/*
		* Debug
		for (int i = 0; i < n; i++)
			printf(" %d", p[i]);
		printf("\n");
		*/
	}

	//output
	for (int i = 0; i < n; i++)
		printf(" %d", p[i]);

	free(p);
	return 0;
}

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
8
8 31 48 73 3 65 20 29
*/
int main() {
	int n, * p;
	int temp, minLoc = 0;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int) * n);

	//input
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	//i = pass
	for (int i = 0; i < n - 1; i++) {
		minLoc = i;

		for (int j = i + 1; j < n; j++) {
			if (p[minLoc] > p[j])
				minLoc = j;		// 더 큰 배열 위치변경
		}

		// swap
		if (i != minLoc) {
			temp = p[i];
			p[i] = p[minLoc];
			p[minLoc] = temp;
		}
		/*
		* Debug
		for (int i = 0; i < n; i++)
			printf(" %d", p[i]);
		printf("\n");
		*/
	}

	//output
	for (int i = 0; i < n; i++)
		printf(" %d", p[i]);

	free(p);
	return 0;
}