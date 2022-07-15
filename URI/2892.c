//C99 21/08/2020
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long int *crivo(long int);
long int *tabela_primos(long int, long int *);
long int *fatores(long int, long int *, long int *);
long int *divisorescv(long int n, long int *F, long int *D);
long long int MDC(long long int, long long int);
long long int mmc(long long int, long long int);
int compare(const void *, const void *);


int main() {
	long int t;
	int a, b, numd;
	long int *crv = crivo(1001);
	long int *tab = tabela_primos(1001, crv);
	long int *fat = calloc(51, sizeof(long int));
	long int *div = calloc(1000, sizeof(long int));

	scanf("%ld %d %d", &t , &a, &b);
	while (t+a+b != 0) {
		fat = fatores(t, tab, fat);
		div = divisorescv(t, fat, div);
		qsort(&(div[1]), div[0], sizeof(long int), compare);

		for (int i = 1; div[i] < t; i++) {
			if ((mmc(mmc(a, b), div[i])) == t) {
				printf("%ld ", div[i]);
			}
		}
		printf("%ld\n", t);

		scanf("%ld %d %d", &t, &a, &b);
	}
	return 0;
}


long int *crivo(long int n) {
	long int *C = malloc(sizeof(long int) * n);
	long int t, d;

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


long int *tabela_primos(long int n, long int *C) {
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


long int *fatores(long int n, long int *P, long int *F) {
	long int np = P[0], nf = 0;

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


long int *divisorescv(long int n, long int *F, long int *D) {
	long int nd = 1, nf = F[0], nda, k;
	F[0] = 1; 
	D[1] = 1;

	for(int i = 1; i <= nf; i++) {
		if (F[i] == F[i-1]) {
			k = k * F[i];
		}
		else {
			k = F[i];
			nda = nd;
		}
		for(int j = 1; j <= nda; j++) {
			D[++nd] = k * D[j];
		}
	}
	D[0] = nd;
	return D;
}


long long int mmc(long long int a, long long int b) {
	return a * b / MDC(a, b);
}


long long int MDC(long long int a, long long int b) {
	if (b == 0) {
		return a;
	}
	return MDC(b, a%b);
}


int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}
