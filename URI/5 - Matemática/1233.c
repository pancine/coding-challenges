//C99 16/08/2020
#include <stdio.h>
#include <math.h>


void crivo(long long int, int *);
void tabela_primos(long long int, int *, int *);
long long int primot(long long int, int *);
void fatorat(long long int, int *, long long int*);
long long int eleva(long long int, int);
long long int fi(long long int *);


int c[31700000], p[4000001];
long long int n, aux = 1, f[50];


int main() {
	while (scanf("%lli",&n) > 0) {
		if (n > aux) {
			crivo(ceil(sqrt(n)), c);
			tabela_primos(ceil(sqrt(n)), c, p);
			aux = n;
		}
		fatorat(n, p, f);
		printf("%lli\n", fi(f));
	}
	return 0;
}


void crivo(long long int n, int *C) {
	long long int t, d;
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
}


void tabela_primos(long long int n, int *C, int *P) {
	long long int np = 0;
	for(int i = 2; i <= n; i++) {
		if (C[i-1] == i) {
			P[++np] = i;
		}
	}
	P[0] = np;
}


long long int primot(long long int n, int *P) {
	long long int np = P[0];

	for(int i = 1; i <= np; i++) {
		if (n % P[i] == 0) {
			if (n != P[i]) {
				return 0;
			}
			return 1;
		}
	}
	return 1;
}


void fatorat(long long int n, int *P, long long int*F) {
	int np = P[0], nf = 0;

	for(int i = 1; i <= np; i++) {
		while (n % P[i] == 0) {
			F[++nf] = P[i];
			n = n/P[i];
		}
		if (n == 1) {
			break;
		}
	}
	if (n != 1) {
		F[++nf] = n;
	}
	F[0] = nf;
}


long long int eleva(long long int n, int k) {
	if (k == 0) {
		return 1;
	}
	else if (k % 2 != 0) {
		return (eleva(n, k-1) * n);
	}
	else {
		long long int x = eleva(n, k/2);
		return (x * x);
	}
}


long long int fi(long long int *F) {
	int nf = F[0], cont = 1;
	long long int aux = F[1], fi = 1;

	for (int i = 2; i <= nf; i++) {
		if (aux == F[i]) {
			cont++;
		}
		else {
			fi = fi * (eleva(aux, cont) - eleva(aux, cont-1));
			aux = F[i];
			cont = 1;
		}
	}
	fi = fi * (eleva(aux, cont) - eleva(aux, cont-1));
	return fi/2;
}
