#include <stdio.h>

int quadrados(int);
int memory[101];

int main() {
	int n;
	memory[0] = -666;
	memory[1] = 1;
	for (int i = 2; i <= 100; i++) {
		memory[i] = -1;
	}
	
	scanf("%d", &n);
	while(n != 0) {
		printf("%d\n", memory[n]);
		scanf("%d", &n);
	}
}

int quadrados(int n) {
	if (memory[n] == -1) {
		memory[n] = quadrados(n-1) + (n*n);
	}
	return memory[n];
}