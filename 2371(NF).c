//C99 23/06/2020
#include <stdio.h>
#include <stdlib.h>

int **creategame(int lin, int col);
void freegame(int **game, int lin);
void fillgame(int **game, int lin, int col);
void printgame(int **game, int lin, int col); //remover
int play(int **game, int x, int y);
int search(int **game, int x, int y, int lin, int col);
int check(int **game, int x, int y);
int count(int **game, int lin, int col);

int main()
{
	//Parte 1: Montando o jogo
	int lin, col;
	int **tabuleiro;
	scanf("%d %d", &lin, &col);
	tabuleiro = creategame(col, lin);
	fillgame(tabuleiro, lin, col);

	//Parte 2: Jogadas
	int k, x, y;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		play(tabuleiro, x, y);
	}

	//Parte 3: Verificando navios
	int cont;
	printgame(tabuleiro, lin, col);
	cont = count(tabuleiro, lin, col);
	printf("%d\n", cont);
	printgame(tabuleiro, lin, col);
	freegame(tabuleiro, lin);
	return 0;
}

int **creategame(int lin, int col) {
	//Cria o jogo vazio
	int **game = NULL;
	if ((game = (int**) malloc(lin * sizeof(int*))) != NULL) {
		for (int i = 0; i < col; i++) {
			if ( (game[i] = (int*) malloc(col * sizeof(int))) == NULL) {
				while (i) {
					i--;
					free(game[i]);
				}
				free(game);
				return NULL;
			}
		}
	}
	return game;
}

void freegame(int **game, int lin) {
	//Limpa memória
	for (int i = 0; i < lin; i++) {
		free(game[i]);
	}
}

void fillgame(int **game, int lin, int col) {
	//Preenche o jogo com 0 e 1
	char str[col];
	for (int x = 0; x < lin; x++) {
		scanf("%s", str);
		for (int y = 0; y < col; y++) {
			if (str[y] == '#') {
				game[x][y] = 1;
			}
			else if (str[y] == '.') {
				game[x][y] = 0;
			}
		}
	}
}

void printgame(int **game, int lin, int col) {
	//printa o jogo (apenas para debug)
	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d", game[i][j]);
		}
		printf("\n");
	}
}

int play(int **game, int x, int y) {
	//Acertos são marcados com 2
	if (game[x-1][y-1] == 1) {
		game[x-1][y-1] = 2;
	}
	return 0;
}

int search(int **game, int x, int y, int lin, int col) {
	//busca numeros 2 consequentes que nao possuem 1 em sequencia (cima, direita, baixo, esquerda)
	printf("%d %d\n", x, y);
	int flag;
	if (x-1 >= 0) {
		flag = check(game, x-1, y);
		printf("!c!%d!\n", flag);
		if (flag == 1) {
			game[x][y] = 0;
			return 0;
		}
		else if (flag == 2) {
			game[x][y] = 0;
			if (search(game, x-1, y, lin, col) == 0) {
				return 0;
			}
		}
	}
	if (y+1 < col) {
		flag = check(game, x, y+1);
		printf("!d!%d!\n", flag);
		if (flag == 1) {
			game[x][y] = 0;
			return 0;
		}
		else if (flag == 2) {
			game[x][y] = 0;
			if (search(game, x, y+1, lin, col) == 0) {
				return 0;
			}
		}
	}
	if (x+1 < lin) {
		flag = check(game, x+1, y);
		printf("!b!%d!\n", flag);
		if (flag == 1) {
			game[x][y] = 0;
			return 0;
		}
		else if (flag == 2) {
			game[x][y] = 0;
			if (search(game, x+1, y, lin, col) == 0) {
				return 0;
			}
		}
	}
	if (y-1 >= 0) {
		flag = check(game, x, y-1);
		if (flag == 1) {
			game[x][y] = 0;
			return 0;
		}
		else if (flag == 2) {
			game[x][y] = 0;
			if (search(game, x, y-1, lin, col) == 0) {
				return 0;
			}
		}
	}
	game[x][y] = 0;
	return 1;
}

int check(int **game, int x, int y) {
	//retorna numero na posicao desejada
	if (game[x][y] == 0) { return 0; }
	else if (game[x][y] == 1) { return 1; }
	else { return 2; }
}

int count(int **game, int lin, int col) {
	//numero de navios completamente acertados
	int navios = 0;
	for (int x = 0; x < lin; x++) {
		for (int y = 0; y < col; y++) {
			if (game[x][y] == 2) {
				if (search(game, x, y, lin, col) == 1) {
					printf("%d%d+1\n",x,y);
					navios++;
				}
			}
		}
	}
	return navios;
}
