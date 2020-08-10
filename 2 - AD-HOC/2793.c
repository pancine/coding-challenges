#include <stdio.h>
#include <stdlib.h>

long long int cont(char *); // O(log n)
long long int eleva(int n, int k); // O(n)

int main() {
	char * str = (char *) malloc(sizeof(char) * 10000007);
	scanf("%s", str);
	long long int particoes = cont(str);
	printf("%lld\n", eleva(2, particoes-1)%1000000007);
	return 0;
}


long long int cont(char *str) {	//Retorna quantas particoes é possivel fazer mod 1000000007
	long long int a[3] = {0, 0, 0};
	for (char *p = &(str[0]); *p != '\0'; p++) {
		if (*p == 77) {
			a[0]++;
		} else {
			a[1]++;
		}
		if (a[0] == a[1]) {
			a[2]++;
		}
	}
	return a[2]%1000000007;
}

long long int eleva(int n, int k) {	//Retorna n^k mod 1000000007
	if (k == 0) {
		return 1;
	}
	else if (k % 2 != 0) {
		return (eleva(n, k-1)%1000000007 * n%1000000007)%1000000007;
	}
	else {
		long long int x = eleva(n, k / 2)%1000000007;
		return (x%1000000007 * x%1000000007) %1000000007;
	}
}