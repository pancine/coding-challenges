//C99 16/08/2020
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int primo(int);
int **create_mat(int, int);
long long int C(int, int);


int main() {
	long long int result = 0;
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	while (N+M+K > 0) {
		int **matriz = create_mat(++N, ++M);

		if (N-1 >= 1 && M-1 >= 1) {
			for (int i = 1; i < N; i++) {
				if (matriz[i][0] >= K)
					result += C(matriz[i][0], K);
			}
			for (int i = 1; i < M; i++) {
				if (matriz[0][i] >= K)
					result += C(matriz[0][i], K);
			}
		}
		else if (N-1 == 1 && M-1 > 1) {
			for (int i = 1; i < M; i++) {
				if (matriz[0][i] >= K)
					result += C(matriz[0][i], K);
			}
		}
		else if (N-1 > 1 && M-1 == 1) {
			for (int i = 1; i < N; i++) {
				if (matriz[i][0] >= K)
					result += C(matriz[i][0], K);
			}
		}
		if (K == 1) {
			printf("%lld\n", result/2);
		}
		else {
			printf("%lld\n", result);
		}

		result = 0;
		scanf("%d %d %d", &N, &M, &K);
	}
	return 0;
}


int primo(int n) { 
	if (n > 1) {
		for(int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}


int **create_mat(int x, int y) {
	int **mat = (int **) malloc(sizeof(int*) * (x));
	for (int i = 0; i < x; i++) {
		mat[i] = (int*) calloc(y+1, sizeof(int));
	}

	for (int i = 1; i < x; i++) {
		for (int j = 1; j < y; j++) {
			mat[i][j] = primo((i-1) * (y-1) + (j-1));
			if (mat[i][j] == 0) {
				mat[0][j] += 1;
				mat[i][0] += 1;
			}
		}
	}
	return mat;
}


long long int C(int n, int p) {
	long long int total = n, div = 1;
	int fim = p;

	if (n == p) {
		return 1;
	}
	if (n-p > p) {
		fim = n-p;
	}
	for (int i = n-1; i > fim; i--) {
		total *= i;
	}
	for (int i = 2; i <= (n-fim); i++) {
		div *= i;
	}
	return total/div;
}