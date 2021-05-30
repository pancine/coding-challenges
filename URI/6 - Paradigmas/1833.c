//C99 14/09/2020
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **create();
float DistanciaEdicao(float **D, char **str1, int n, char **str2, int m, int ppm);
void Transforma(int **D, char **A, char **B, int i, int j);
float min(float a, float b, float c);

float Custo[4];

int main() {
	int casos, ppm, num_lamp1, num_lamp2, i, caso = 1, cont = 0;
	char **lamp1 = create(), **lamp2 = create(), number[100];

	float **D = (float **) malloc(sizeof(float *) * 101);
	for (i = 0; i < 101; i++)
		D[i] = (float *) malloc(sizeof(float) * 101);

	scanf("%d", &casos);
	while (casos--) {
		for (i = 0; i < 4; i++)
			Custo[i] = 0;
		cont = 0;

		scanf("%d %d", &ppm, &num_lamp1);
		for (i = 1; i <= num_lamp1; i++) 
				scanf("%s", lamp1[i]);

		scanf("%d", &num_lamp2);
		for (i = 1; i <= num_lamp2; i++) 
				scanf("%s", lamp2[i]);

		if (num_lamp1 && num_lamp2) {
			Custo[3] = DistanciaEdicao(D, lamp1, num_lamp1, lamp2, num_lamp2, ppm);
		}
		else if (num_lamp1)
			Custo[3] = (num_lamp1 * 0.5 * ppm);
		else if (num_lamp2) 
			Custo[3] = (num_lamp2 * 2.5 * ppm);
		else 
			Custo[3] = 0;
		
		sprintf(number, "%f", Custo[3]);
		for (char *k = number; *k != '.'; k++)
			cont++;

		number[cont] = ',';
		number[cont+3] = '\0';
		printf("Caso #%d: R$ %s\n", caso++, number);
	}
	free(lamp1);
	free(lamp2);
	free(D);

	return 0;
}

char **create() {
	char **list = (char **) malloc(sizeof(char *) * 111);
	for (int i = 0; i < 111; i++) {
		list[i] = (char *) malloc(sizeof(char) * 55);
	}
	return list;
}

float DistanciaEdicao(float **D, char **str1, int n, char **str2, int m, int ppm) {
	int i, j;

	for (i = 0; i <= n; i++)
		D[i][0] = i * ppm * 0.5;
	for (j = 0; j <= m; j++)
		D[0][j] = j * ppm * 2.5;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (strcmp(str1[i], str2[j]) == 0)
				D[i][j] = D[i-1][j-1];
			else 
				D[i][j] = min(D[i-1][j] + (ppm * 0.5), D[i][j-1] + (ppm * 2.5), D[i-1][j-1] + (ppm*1));
		}
	}
	return D[n][m];
}

float min(float a, float b, float c) {
	if (a <= b && a <= c) 
		return a;
	else if (b <= a && b <= c)
		return b;
	return c;
}
