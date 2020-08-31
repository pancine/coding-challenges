#include <stdio.h>

long long int eleva(int n, int k);

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", eleva(3,n));
	return 0;
}

long long int eleva(int n, int k) {
	if (k == 0) {
		return 1;
	}
	else if (k % 2 != 0) {
		return (eleva(n, k-1)%2147483647 * n%2147483647)%2147483647;
	}
	else {
		long long int x = eleva(n, k/2)%2147483647;
		return (x%2147483647 * x%2147483647)%2147483647;
	}
}