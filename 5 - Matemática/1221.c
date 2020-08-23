//C99 15/08/2020
#include <stdio.h>
#include <math.h>

int primo(long int n);

int main() {
	int n;
	long int x;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%li", &x);
		if (primo(x) && x > 2) {
			printf("Prime\n");
		}
		else if (x == 2) {
			printf("Prime\n");
		}
		else {
			printf("Not Prime\n");
		}
	}
	return 0;
}


int primo(long int n) { 
	for (int i = 2; i <= ceil(sqrt(n)); i++) {
		if (n%i == 0) {
			return 0;
		}
	}
	return 1;
}