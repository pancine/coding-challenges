//C99 15/09/2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **create_list();
void locais(char *coordenadas, char **matriz, int x, int y);
void SMC(char *n, char *m);
int max(int a, int b);

int caso = 1;

int main() {
	int casos_teste, linhas, colunas, num_passos, num_passos2, x, y, i;
	char passos[512], passos2[512];
	char **matriz = create_list();
	scanf("%d", &casos_teste);

	while (casos_teste--) {
		scanf("%d %d", &linhas, &colunas);
		for (i = 1; i <= linhas; i++) {
			scanf("%s", &(matriz[i][1]));
		}

		scanf("%d %d %d", &num_passos, &x, &y);
		passos[1] = matriz[x][y];
		if (num_passos) {
			scanf("%s", &(passos[2]));
			locais(passos, matriz, x, y);
		}
		else {
			passos[2] = '\0';
		}

		scanf("%d %d %d", &num_passos2, &x, &y);
		passos2[1] = matriz[x][y];
		if (num_passos2) {
			scanf("%s", &(passos2[2]));
			locais(passos2, matriz, x, y);
		}
		else {
			passos2[2] = '\0';
		}
		
		SMC(passos, passos2);
	}
	return 0;
}

char **create_list() {
	char **string = (char **) malloc(sizeof(char *) * 21);
	for (int i = 0; i < 20; i++) {
		string[i] = (char *) malloc(sizeof(char) * 23);
	}
	return string;
}

void locais(char *coordenadas, char **matriz, int x, int y) {
	int tx = x, ty = y;

	for (char *i = &coordenadas[2]; *i != '\0'; i++) {
		if (*i == 'N') {
			*i = matriz[--tx][ty];
		}
		else if (*i == 'E') {
			*i = matriz[tx][++ty];
		}
		else if (*i == 'S') {
			*i = matriz[++tx][ty];
		}
		else {
			*i = matriz[tx][--ty];
		}
	}
}

void SMC(char *n, char *m) {
	int a = strlen(&n[1]), b = strlen(&m[1]), i, j;

	int **T = (int **) malloc(sizeof(int *) * (a+1));
	for (i = 0; i <= a; i++)
		T[i] = (int *) malloc(sizeof(int) * (b+1));

	for (i = 0; i <= a; i++) 
		T[i][0] = 0;
	for (j = 0; j <= b; j++)
		T[0][j] = 0;

	for (i = 1; i <= a; i++) {
		for (j = 1; j <= b; j++) {
			if (n[i] == m[j])
				T[i][j] = T[i-1][j-1] + 1;
			else
				T[i][j] = max(T[i-1][j], T[i][j-1]);
		}
	}
	printf("Case %d: %d %d\n", caso++, a - T[a][b], b - T[a][b]);
}

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	return b;
}