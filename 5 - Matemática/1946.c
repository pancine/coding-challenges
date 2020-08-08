//C99 08/08/2020
#include <stdio.h>
#include <stdlib.h>

void createmat(int);
float recursao(int, int);

float **mat;

int main() {
	int n;
	scanf("%d", &n);
	createmat(n);
	printf("%.2f\n", recursao(n-1, (n-1)/2)*200);
	return 0;
}

void createmat(int n) {
	mat = (float**) malloc((n+1)*sizeof(float*));
	for (int i = 0; i < n; i++) {
		mat[i] = (float*) malloc((n+1)*sizeof(float));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = -1.0;
			if (j>i) {
				mat[i][j] = 0.0;
			}
		}
	}
	mat[0][0] = 1.0; mat[1][0] = 0.5; mat[1][1] = 0.5;
}

float recursao(int i, int j) {
	if (i < 0 || j < 0) {
		return 0;
	}
	else if (i == 0) {
		mat[i][j] = recursao(i-1,j)/2;
	}
	else if (mat[i][j] == -1.0) {
		mat[i][j] = recursao(i-1, j-1) + recursao(i-1, j);
	}
	return mat[i][j]/2;
}