//C99 22/03/2020
#include <stdio.h>

int perseguir(int);

int main()
{
	int i, cont, min = 1;
	int aves, num_l;
	scanf("%d %d", &aves, &num_l);
	for (i = 0; i < aves; i++)
	{
		cont = perseguir(num_l);
		if (min < cont) min = cont;
	}
	printf("%d\n", min);
	return 0;
}

int perseguir(int nloc)
{
	int ave, cont = 0, qmov, ant;
	scanf("%d", &qmov);
	scanf("%d", &ave); 
	qmov--;
	while (qmov > 0)
	{
		ant = ave;
		scanf("%d", &ave);
		qmov--;
		if (ant > ave)
		{
			cont++;
		}
	}
	if (ave != 0) return cont + 1;
	else return cont;
}
