//C99 21/09/2020
#include <stdio.h>

void swap(int *a, int *b);
int max(int a, int b);

int main() {
	int lado, comprimento, raio1, raio2;
	scanf("%d %d %d %d", &lado, &comprimento, &raio1, &raio2);
	while (lado+comprimento+raio1+raio2 > 0) {
		if (comprimento < lado) {
			swap(&comprimento, &lado);
		} //lado sempre menor
		if (2 * max(raio1, raio2) > lado || (raio1+raio2)*(raio1+raio2) > (lado-(raio1+raio2))*(lado-(raio1+raio2)) + (comprimento-(raio1+raio2))*(comprimento-(raio1+raio2))) {
			printf("N\n");
		}
		else {
			printf("S\n");
		}
		scanf("%d %d %d %d", &lado, &comprimento, &raio1, &raio2);	
	}
	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}