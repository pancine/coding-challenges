//C99 13/05/2020
#include <stdio.h>

int main()
{
	int n, custo = 7;
	scanf("%d\n", &n);
	if (n < 10)
	{
		printf("%d\n", custo);
	}
	else if (n < 30)
	{
		custo += n - 10;
		printf("%d\n", custo);
	}
	else if (n < 100)
	{
		custo += 20 + (n-30)*2;
		printf("%d\n", custo);
	}
	else
	{
		custo += 160 + (n-100)*5;
		printf("%d\n", custo);
	}
	return 0;
}
