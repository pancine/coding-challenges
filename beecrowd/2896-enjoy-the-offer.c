//C99 08/11/2019
#include <stdio.h>

int main()
{
	int T, N, K;
	fscanf(stdin, "%d", &T);
	while(T > 0)
	{
		fscanf(stdin, "%d %d", &N, &K);
		printf("%d\n", (N%K) + (N/K));
		T--;
	}
	return 0;
}
