#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
7
3 73 48 31 8 11 20 
8
73 65 48 31 29 20 8 3
*/
int main() {
	int n, *p, t;
	int temp, max = 0;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int) * n);

	//input
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for (int i = 1; i < n; i++) {
		//i = pass
		t = i;

		for (int j = i - 1; j >= 0; j--) {
			
			if (p[t] > p[j])
				break;

			//swap
			temp = p[t];
			p[t] = p[j];
			p[j] = temp;

			t = j;
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

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
7
3 73 48 31 8 11 20
8
73 65 48 31 29 20 8 3
*/

int main() {
	int n, * p, t, j, i;
	int temp, max = 0;

	scanf("%d", &n);

	p = (int*)malloc(sizeof(int) * n);

	//input
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);

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
	//output
	for (int i = 0; i < n; i++)
		printf(" %d", p[i]);

	free(p);
	return 0;
}
