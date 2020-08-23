//C99 19/08/2020
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long int *crivo(long long int);
long int *tabela_primos(long long int, long int *);
long long int *fatores(long long int, long int *, long long int *);
int divisores(long long int *);


int main() {
	long long int n, div;
	long int *crv = crivo(ceil(sqrt(900000000000000)));
	long int *tab = tabela_primos(ceil(sqrt(900000000000000)), crv);
	long long int *fat = malloc(sizeof(long long int) * 51);

	while (scanf("%lld", &n) != EOF) {
		fat = fatores(n, tab, fat);
		div = divisores(fat);
		printf("%d\n", div);
	}
	return 0;
}


long int *crivo(long long int n) {
	long int *C = malloc(sizeof(long int) * n);
	long long int t, d;

	for (long int i = 1; i < n; i++) {
		C[i] = i + 1;
		if ((i + 1) % 2 == 0) {
			C[i] = 2;
		}
	}
	for (long int i = 3; i <= ceil(sqrt(n)); i++) {
		if (C[i - 1] == i) {
			t = i * i;
			d = i + i;
			while (t <= n) {
				if (C[t-1] == t) {
					C[t-1] = i;
				}
				t += d;
			}
		}
	}
	return C;
}


long int *tabela_primos(long long int n, long int *C) {
	long int *tabp = malloc(sizeof(long int) * n);
	long int np = 0;

	for (long int i = 2; i <= n; i++) {
		if (C[i - 1] == i) {
			tabp[++np] = i;
		}
	}
	tabp[0] = np;
	return tabp;
}


long long int *fatores(long long int n, long int *P, long long int *F) {
	long long int np = P[0], nf = 0;

	for (long int i = 1; P[i] <= np; i++) {
		while (n % P[i] == 0) {
			F[++nf] = P[i];
			n = n / P[i];
		} 
		if (n == 1) {
			break;
		}
	}
	if (n != 1) {
		F[++nf] = n;
	}
	F[0] = nf;
	return F;
}


int divisores(long long int *F) {
	int nd = 1, nda;
	long long int nf = F[0];
	F[0] = 1;

	for (int i = 1; i <= nf; i++) {
		if (F[i]%2 != 0) {
			if (F[i] != F[i - 1]) {
				nda = nd;
			}
			nd += nda;
		}
	}
	return nd;
}
