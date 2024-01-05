//C99 25/08/2020
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int NF(char *number);
int mod9(long long int n);
long long int esq_dir(int number, char *power);
long long int eleva(int n, int k);


int main() {
	int N, result;
	char *b = (char *) malloc(sizeof(char) * 100001);
	char *e = (char *) malloc(sizeof(char) * 100001);
	scanf("%s %s", b, e);

	result = esq_dir(NF(b), e);
	printf("%d\n", result);
	
	free(b); free(e);
	return 0;
}


int NF(char *number) {
	long int convert = 0;

	for (char *i = number; *i != '\0'; i++) {
		convert += (*i-48);
	}
	convert %= 9;
	
	if (convert == 0){
		return 9;
	}
	return (int) convert;
}


int mod9(long long int n) {
    if ((n%9) == 0) {
        return 9;
    }
    return (n%9);
}


long long int esq_dir(int number, char *power) {
	long long int temp = 1, fim = strlen(power);
	int memory[10];

	for (int i = 0; i < 10; i++) {
		memory[i] = mod9(eleva(number, i));
	}
	for (long int i = 0; i < fim-1; i++) {
		temp *= mod9(eleva(memory[(power[i]-48)], 10));
		temp = mod9(temp);
	}
	temp *= memory[power[fim-1]-48];
	temp = mod9(temp);

	return temp;
}

long long int eleva(int n, int k) {	
	if (k == 0) {
		return 1;
	}
	else if (k % 2 != 0) {
		return (eleva(n, k-1) * n);
	}
	else {
		long long int x = eleva(n, k / 2);
		return (x * x);
	}
}