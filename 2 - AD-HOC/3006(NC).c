#include <stdio.h>
#include <ctype.h>

int cr(char *);
int find_r(char *);
int find_cf(char *, char, char);
int dcase(char *, int, char *);

int main()
{
	/* n = NUMERO DE CASOS DE TESTE
	cont_r = QUANTIDADE DE R's
	pos_r = POSIÇÃO DO R(ATUAL)
	dist[4] = LISTA COM AS 4 OPÇÕES POSSIVEIS JÁ REMOVIDAS AS SUB-OPÇÕES
	min = MENOR VALOR
	str[~] = STRING COM O CASO TESTE
	*p = PONTEIRO PARA A STRING
	*/
    int n, cont_r, pos_r = 0, dist[4], min = 999999;
    char str[1000001];
    char *p = str;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", str);
        cont_r = cr(str);
        pos_r = 0;
        p = str;
        min = 999999;

        for (int j = 0; j < cont_r; j++)
        {
            pos_r += find_r(&(str[pos_r]));
            dist[0] = dcase("cl", pos_r, &(p[pos_r]));
            dist[1] = dcase("cr", pos_r, &(p[pos_r]));
            dist[2] = dcase("fl", pos_r, &(p[pos_r]));
            dist[3] = dcase("fr", pos_r, &(p[pos_r]));
            pos_r++;
        }

        for (int j = 0; j < 4; j++)
        {
            if (dist[j] < min && dist[j] > 0)
            {
                min = dist[j];
            }
        }
        printf("%d\n", min);
    }
    return 0;
}

int cr(char *str)
{
    // Contabiliza a quantidade de R's dentro da string
    char *p = str;
    int cont = 0;
    while (isgraph(*p))
    {
        if (*p == 'R')	cont++;
        p++;
    }
    return cont;
}

int find_r(char *str)
{
    // Acha a posição do proximo R
    int i = 0;
    char *p1 = str;
    while(*p1 != 'R')
    {
        p1++;
        i++;
    }
    return i;
}

int find_cf(char *str, char side, char seek)
{
    // A partir da posição indicada, busca a letra na variavel 'seek'(C=cafe ou F=farmacia) indo para o lado na variavel 'lado'(e=esquerda ou d= direita) e retorna a posição
    int  i = 0;
    char *p = str;
    if (side == 'l')
    {
        while(*p != seek)
        {
            p--;
            i++;
            if (!isgraph(*p)) return -1;
        }
    }
    else
    {
        while(*p != seek)
        {
            p++;
            i++;
            if (!isgraph(*p)) return -1;
        }
    }
    return i;
}

int dcase(char *inst, int pos_r, char *p)
{ /* Sabendo que as possiveis distancias são dadas por uma dessas opções: 
	C para esquerda e então: F ou esquerda ou F direita
	C para direita e então: F ou esquerda ou F direita
	F para esquerda e então: C ou esquerda ou C direita
	F para direita e então: C ou esquerda ou C direita
	Essa funçao retorna a menor distancia entre as duas opções de cada uma das opções acima.
	*/
    int dist_l = 0, dist_r = 0, dist = 0, ch;
    if (inst[0] == 'c')
    {
        if (inst[1] == 'l')
        {
            ch = find_cf(p, 'l', 'C');
            if (ch == -1) return -1;
            dist_l = find_cf(&(p[-ch]), 'l', 'F');
            dist_r = find_cf(&(p[-ch]), 'r', 'F');
        }
        else
        {
            ch = find_cf(p, 'r', 'C');
            if (ch == -1) return -1;
            dist_l = find_cf(&(p[ch]), 'l', 'F');
            dist_r = find_cf(&(p[ch]), 'r', 'F');
        }
    }
    else
    {
        if (inst[1] == 'l')
        {
            ch = find_cf(p, 'l', 'F');
            if (ch == -1) return -1;
            dist_l = find_cf(&(p[-ch]), 'l', 'C');
            dist_r = find_cf(&(p[-ch]), 'r', 'C');
        }
        else
        {
            ch = find_cf(p, 'r', 'F');
            if (ch == -1) return -1;
            dist_l = find_cf(&(p[ch]), 'l', 'C');
            dist_r = find_cf(&(p[ch]), 'r', 'C');
        }
    }
    if (dist_l < 0 || dist_r < 0)
    {
        if (dist_l == -1) dist = ch + dist_r;
        else dist = ch + dist_l;
    }
    else if (dist_l > dist_r) dist = ch + dist_r;
    else dist = ch + dist_l;
    return dist;
}
