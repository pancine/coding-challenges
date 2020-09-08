//C99 07/09/2020
#include <stdio.h>

int SCM(int n, int *S);
int BuscaBin(int *T, int ini, int fim, int x);

int main() {
	int n, x[500001], i;
	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; i++)
			scanf("%d", &x[i]);

		printf("%d\n", SCM(n,x));
	}
	return 0;
}

int SCM(int n, int *S) {
	int k = 1, T[n], O[n], j;
	T[1] = S[1];
	O[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (S[i] > T[k]) {
			k++;
			T[k] = S[i];
			O[i] = k;
		}
		else {
			j = BuscaBin(T, 1, k, S[i]);
			T[j] = S[i];
			O[i] = j;
		}
	}
	return k;
}

int BuscaBin(int *T, int ini, int fim, int x) { 
	int m;
    if (ini > fim)
        return ini;
    else {
        m = (ini + fim)/2;
        if(T[m] < x) {
            return BuscaBin(T, m+1, fim, x);
        }
        else{
        	return BuscaBin(T, ini, m-1, x);
        }
    }
}