//C99 31/08/2020
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int *crivo(int n);
int *tabela_primos(int n, int *C);
int fatorat(long long int n, int *P);


int main() {
	int *crv, *tabela;
	long long int n = 1, fatores[3];
	crv = crivo(1000000);
	tabela = tabela_primos(1000000, crv);
	scanf("%lld", &n);
	while (n != 0) {
		fatores[0] = fatorat(n, tabela);
		fatores[1] = fatorat(n/fatores[0], tabela);
		fatores[2] = fatorat(n/(fatores[0]*fatores[1]), tabela);
		printf("%lld = %lld x %lld x %lld\n", n, fatores[0], fatores[1], fatores[2]);
		scanf("%lld", &n);
	}
	return 0;
}


int *crivo(int n) {
	int *C = (int *) malloc(sizeof(int) * n);
	int t, d;
	for(int i = 1; i < n; i++) {
		C[i] = i+1;
		if ((i+1)%2 == 0) {
			C[i] = 2;
		}
	}
	for(int i = 3; i <= ceil(sqrt(n)); i++) {
		if (C[i-1] == i) {
			t = i*i;
			d = i+i;
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


int *tabela_primos(int n, int *C) {
	int *P = (int *) malloc(sizeof(int) * n);
	int np = 0;
	for(int i = 2; i <= n; i++) {
		if (C[i-1] == i) {
			P[++np] = i;
		}
	}
	P[0] = np;
	return P;
}


int fatorat(long long int n, int *P) {
	int np = P[0], nf = 0;
	for(int i = 1; i <= np; i++) {
		if (n % P[i] == 0) {
			return P[i];
		}
	}
}