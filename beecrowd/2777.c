//C99 10/08/2020
#include <stdio.h>
#include <stdlib.h>

long long int **create_mat();
long long int **mult(long long int **, long long int **);
long long int **Exp(long long int **, long long int);
long long int **id();

int main() {
	long long int n, R;

	long long int **A = create_mat();
	A[0][0] = 0; A[0][1] = 1; A[0][2] = 1;
	A[1][0] = 1; A[1][1] = 0; A[1][2] = 0;
	A[2][0] = 0; A[2][1] = 1; A[2][2] = 0;

	while(scanf("%lld", &n) != EOF) {
		if (n > 3) {
			long long int **T = Exp(A,n-3);
			R = ((T[0][0]%1000000007 * 2)%1000000007 + (T[0][1]%1000000007 * 2)%1000000007 + (T[0][2]%1000000007)%1000000007)%1000000007;
		} else if (n == 1) {
			R = 1;
		} else if (n == 2) {
			R = 2;
		} else {
			R = 2;
		}
		printf("%lld\n", R);
	}
	return 0;
}


long long int **create_mat() {
	long long int **mat;

	mat = (long long int**) malloc(sizeof(long long int *) * (4));
	for (int i = 0; i < 3; i++) {
		mat[i] = (long long int*) malloc(sizeof(long long int) * (4));
	}
	return mat;
}


long long int **mult(long long int **A, long long int **B) {
	long long int **R = create_mat();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			R[i][j] = 0;
			for (int z = 0; z < 3; z++) {
				R[i][j] = (R[i][j]%1000000007 + (A[i][z]%1000000007 * B[z][j]%1000000007)%1000000007)%1000000007;
			}
		}
	}
	return R;
}


long long int **Exp(long long int **A, long long int n) {
	long long int **X = create_mat();
	if (n == 0) {
		return id();
	}
	else if (n == 1) {
		return A;
	}
	else if (n%2 != 0) {
		return mult(Exp(A, n-1), A);
	}
	else {
		X = Exp(A, n/2);
		return mult(X, X);
	}
}


long long int **id() {
	long long int **mat_id = create_mat();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat_id[i][j] = 0;
			if (i == j){
				mat_id[i][j] = 1;
			}
		}
	}
	return mat_id;
}