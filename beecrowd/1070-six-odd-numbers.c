//C99 09/11/2019
#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	if (N%2 == 0){
		N++;
		for (int i = 0; i < 6; ++i){
			printf("%d\n", N);
			N = N + 2;
		}
	}
	else{
		for (int i = 0; i < 6; ++i){
			printf("%d\n", N);
			N = N + 2;
		}
	}
	return 0;
}
