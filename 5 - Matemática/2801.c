//C99 31/08/2020
#include <stdio.h>
#include <stdlib.h>

struct triple{
    int d, x, y;
};

long long int MDC(int, int);
long long int modinv(int, int);
struct triple MDCE(int, int);


int main() {
	int num_entradas, i;
	scanf("%d", &num_entradas);
	
	long long int *mensagem = malloc(sizeof(long long int) * num_entradas);
	long int tam_alfabeto, A, B;
	for (i = 0; i < num_entradas; i++) {
		scanf("%lld", &mensagem[i]);
	}
	scanf("%ld %ld %ld", &tam_alfabeto, &A, &B);

	if (MDC(A, tam_alfabeto) == 1) {
		long long int invA = modinv(A, tam_alfabeto);
		for (i = 0; i < num_entradas; i++) {
			mensagem[i] = ((mensagem[i] - B)*invA)%tam_alfabeto;
			if (mensagem[i] < 0) {
				mensagem[i] += tam_alfabeto;
			}
		}
		for (i = 0; i < num_entradas-1; i++) {
			printf("%lld ",mensagem[i]);
		}printf("%lld\n", mensagem[num_entradas-1]);
	}
	else {
		printf("DECIFRAGEM AMBIGUA\n");
	}
	return 0;
}

long long int MDC(int a, int b) {
	if (b == 0) {
		return a;
	}
	return MDC(b, a%b);
}

long long int modinv(int a, int z) {
    struct triple temp = MDCE(a, z);
    return (temp.x%z + z) % z;
}

struct triple MDCE(int a, int b) {
    struct triple temp;
    if (b == 0) {
        temp.d = a;
        temp.x = 1;
        temp.y = 0;
        return temp;
    }
    else {
        int x1, y1;
        temp = MDCE(b, a%b);
        x1 = temp.y;
        y1 = temp.x - (a/b) * temp.y;
        temp.x = x1;
        temp.y = y1;
        return temp;
    }
}