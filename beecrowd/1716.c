//C99 31/08/2020
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


struct triple{
    long long int d, x, y;
};

long long int *crivo(long long int n);
long long int *tabela_primos(long long int n, long long int *C);
long long int *fatorat(long long int n, long long int *P);
long long int modinv(long long int a, long long int z);
struct triple MDCE(long long int a, long long int b);
long long int eleva(long long int n, long long int k, long long int z);


long long int main() {
	long long int *crv, *tabela, *fatores, n, e, mensagem, totiente, d;
	crv = crivo(1000000);
	tabela = tabela_primos(1000000, crv);
	scanf("%lld %lld %lld", &n, &e, &mensagem);
	
	fatores = fatorat(n, tabela);
	totiente = (fatores[1]-1) * (fatores[2]-1);
	d = modinv(e, totiente);

	printf("%lld\n", eleva(mensagem, d, n));
	return 0;
}


long long int *crivo(long long int n) {
	long long int *C = (long long int *) malloc(sizeof(long long int) * n);
	long long int t, d;
	for(long long int i = 1; i < n; i++) {
		C[i] = i+1;
		if ((i+1)%2 == 0) {
			C[i] = 2;
		}
	}
	for(long long int i = 3; i <= ceil(sqrt(n)); i++) {
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


long long int *tabela_primos(long long int n, long long int *C) {
	long long int *P = (long long int *) malloc(sizeof(long long int) * n);
	long long int np = 0;
	for(long long int i = 2; i <= n; i++) {
		if (C[i-1] == i) {
			P[++np] = i;
		}
	}
	P[0] = np;
	return P;
}


long long int *fatorat(long long int n, long long int *P) {
	long long int *F = (long long int *) malloc(sizeof(long long int) * 51);
	long long int np = P[0], nf = 0;
	for(long long int i = 1; i <= np; i++) {
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
	return F;
}


long long int modinv(long long int a, long long int z) {
    struct triple temp = MDCE(a, z);
    return (temp.x%z + z) % z;
}


struct triple MDCE(long long int a, long long int b) {
    struct triple temp;
    if (b == 0) {
        temp.d = a;
        temp.x = 1;
        temp.y = 0;
        return temp;
    }
    else {
        long long int x1, y1;
        temp = MDCE(b, a%b);
        x1 = temp.y;
        y1 = temp.x - (a/b) * temp.y;
        temp.x = x1;
        temp.y = y1;
        return temp;
    }
}


long long int eleva(long long int n, long long int k, long long int z) {
	if (k == 0) {
		return 1;
	}
	else if (k % 2 != 0) {
		return (eleva(n, k-1, z)%z * n%z)%z;
	}
	else {
		long long int x = eleva(n, k/2, z)%z;
		return (x%z * x%z)%z;
	}
}