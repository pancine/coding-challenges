//C99 14/08/2020
#include <stdio.h>
#include <stdlib.h>


long long int **create_mat(long long int);
long long int **mult(long long int **, long long int **, long long int);
long long int **Exp(long long int **, long long int, long long int);
long long int **id(long long int);


int main() {
	long long int n, k, l, **An, **R;

	long long int **A = create_mat(2);
	A[1][0] = 1; A[1][1] = 0;
	
	long long int **B = create_mat(2);
	B[0][1] = 0; B[1][1] = 0;

	while (scanf("%lld %lld %lld", &n, &k, &l) != EOF) {
		if (n != 5) {
			k = k%1000000; l = l%1000000;
			A[0][0] = k; A[0][1] = l;
			B[0][0] = ((k%1000000 * k%1000000)%1000000+l%1000000)%1000000; B[1][0] = k;
			
			An = mult(Exp(A, (n/5)-2, 2), B, 2);
			printf("%06lld\n", An[0][0]);
		}
		else {
			printf("%06lld\n", k);
		}
	}
	return 0;
}


long long int **create_mat(long long int k) {
	long long int **mat;

	mat = (long long int **) malloc(sizeof(long long int *) * (k + 1));
	for (int i = 0; i < k+1; i++) {
		mat[i] = (long long int *) malloc(sizeof(long long int) * (k + 1));
	}
	return mat;
}


long long int **mult(long long int **A, long long int **B, long long int k) {
	long long int **R = create_mat(k);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			R[i][j] = 0;
			for (int z = 0; z < k; z++) {
				R[i][j] = (R[i][j]%1000000 + (A[i][z]%1000000 * B[z][j]%1000000)%1000000)%1000000;
			}
		}
	}
	return R;
}


long long int **Exp(long long int **A, long long int n, long long int k) {
	long long int **X = create_mat(k);
	if (n == 0) {
		return id(k);
	}
	else if (n == 1) {
		return A;
	}
	else if (n % 2 != 0) {
		return mult(Exp(A, n-1, k), A, k);
	}
	else {
		X = Exp(A, n/2, k);
		return mult(X, X, k);
	}
}


long long int **id(long long int k) {
	long long int **mat_id = create_mat(k);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			mat_id[i][j] = 0;
			if (i == j) {
				mat_id[i][j] = 1;
			}
		}
	}
	return mat_id;
}