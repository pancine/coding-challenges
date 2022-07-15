//C99 24/06/2020
#include <stdio.h>
#include <stdlib.h>

#define NAVIO '#'
#define HIT 'F'
#define VERIFICADO 'C'

char **creategame(int lin, int col);
void freegame(char **game, int lin);
void fillgame(char **game, int lin, int col);
int play(char **game, int x, int y);
int verify(char **game, int x, int y, int lin, int col);
int contando(char **game, int lin, int col);

int main()
{
	int lin, col;
	char **tabuleiro;
	scanf("%d %d", &lin, &col);
	tabuleiro = creategame(col, lin);
	fillgame(tabuleiro, lin, col);
	int k, x, y;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		play(tabuleiro, x, y);
	}
	printf("%d\n", contando(tabuleiro, lin, col));
	return 0;
}

char **creategame(int lin, int col) {
	char **game = NULL;
	if ((game = (char**) malloc(101 * sizeof(char*))) != NULL) {
		for (int i = 0; i < col; i++) {
			if ( (game[i] = (char*) malloc(101 * sizeof(char))) == NULL) {
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

void freegame(char **game, int lin) {
	for (int i = 0; i < lin; i++) {
		free(game[i]);
	}
}

void fillgame(char **game, int lin, int col) {
	for (int i = 0; i < lin; i++) {
		scanf("%s", game[i]);
	}
}

int play(char **game, int x, int y) {
	if (game[x-1][y-1] == NAVIO) {
		game[x-1][y-1] = HIT;
	}
	return 0;
}

int verify(char **game, int x, int y, int lin, int col) {	int flag = 1;
	game[x][y] = VERIFICADO;
	if (x-1 >= 0) {
		if (game[x-1][y] == NAVIO) {
			flag = 0;
		}
		else if (game[x-1][y] == HIT) {
			flag = (verify(game, x-1, y, lin, col) && flag);
		}
	}
	if (x+1 < lin) {
		if (game[x+1][y] == NAVIO) {
			flag = 0;
		}
		else if (game[x+1][y] == HIT) {
			flag = (verify(game, x+1, y, lin, col) && flag);
		}
	}
	if (y-1 >= 0) {
		if (game[x][y-1] == NAVIO) {
			flag = 0;
		}
		else if (game[x][y-1] == HIT) {
			flag = (verify(game, x, y-1, lin, col) && flag);
		}
	}
	if (y+1 < col) {
		if (game[x][y+1] == NAVIO) {
			flag = 0;
		}
		else if (game[x][y+1] == HIT) {
			flag = (verify(game, x, y+1, lin, col) && flag);
		}
	}
	return flag;
}

int contando(char **game, int lin, int col) {
	int cont = 0;
	for (int x = 0; x < lin; x++) {
		for (int y = 0; y < col; y++) {
			if (game[x][y] == HIT) {
				if (verify(game,x,y,lin,col))
					cont++;
			}
		}
	}
	return cont;
}