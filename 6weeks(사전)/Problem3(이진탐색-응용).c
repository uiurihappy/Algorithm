#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b, n, mid = 0;
	char* yn;

	scanf("%d %d %d", &a, &b, &n);
	getchar();

	yn = (char*)malloc(sizeof(char) * n);
	scanf("%s", yn);
	
	for (int i = 0; i < n; i++) {
		mid = (a + b) / 2;
		if (yn[i] == 'Y')
			a = mid + 1;
		else if (yn[i] == 'N')
			b = mid;
	}
	printf("%d", a);

}