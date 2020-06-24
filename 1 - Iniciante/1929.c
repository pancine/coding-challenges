//C99 13/05/2020
#include <stdio.h>
#include <math.h>

int try(int, int, int);

int main()
{
	int A,B,C,D;
	int flag[4];
	scanf("%d %d %d %d", &A, &B, &C, &D);
	flag[0] = try(A,B,C);
	flag[1] = try(A,B,D);
	flag[2] = try(A,C,D);
	flag[3] = try(B,C,D);
	for (int i=0; i < 4; i++)
	{
		if (flag[i] == 1)
		{
			printf("S\n");
			return 0;
		}
	}
	printf("N\n");
	return 0;
}

int try(int a, int b, int c)
{
	int flag = 1;
	flag = ((fabs(b-c)<a)&&(a<b+c)) ? 1 : 0;
	flag = ((fabs(a-c)<b)&&(b<a+c)) ? 1 : 0;
	flag = ((fabs(a-b)<c)&&(c<a+b)) ? 1 : 0;
	return flag;
}
