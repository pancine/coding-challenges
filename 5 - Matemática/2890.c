#include <stdio.h>

long long int C(int, long long int);

int main () {
	int n;
    long long int result;
	do {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
        else if (n < 4) {
			printf("%lld\n", C(n+3, 4)%1000007);
		}
        else {
            result = (C(n+3, 4)%1000007 + C(n, 4)%1000007)%1000007;
			printf("%lld\n", result);
		}
	} while (n != 0);
	return 0;
}

long long int C(int n, long long int p) {
	if (p == 0) {
		return 1;
	}
    else {
		return (C(n-1, p-1) * n / p);
	}
}