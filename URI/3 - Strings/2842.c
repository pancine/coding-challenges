//C99 13/09/2020
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SMC(char *n, char *m);
int max(int a, int b);

int main() {
	char *a = (char *) malloc(sizeof(char) * 5010);
	char *b = (char *) malloc(sizeof(char) * 5010);
	scanf("%s %s", &a[1], &b[1]);
	printf("%d\n", SMC(a,b));

	return 0;
}

int SMC(char *n, char *m) {
	int a = strlen(&n[1]), b = strlen(&m[1]), i, j;

	int **T = (int **) malloc(sizeof(int *) * (a+1));
	for (i = 0; i <= a; i++)
		T[i] = (int *) malloc(sizeof(int) * (b+1));

	for (i = 0; i <= a; i++) 
		T[i][0] = 0;
	for (j = 0; j <= b; j++)
		T[0][j] = 0;

	for (i = 1; i <= a; i++) {
		for (j = 1; j <= b; j++) {
			if (n[i] == m[j])
				T[i][j] = T[i-1][j-1] + 1;
			else
				T[i][j] = max(T[i-1][j], T[i][j-1]);
		}
	}
	return T[a][b];
}

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	return b;
}
