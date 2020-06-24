//C99 21/03/2020
#include <stdio.h>
#include <math.h>

int check(int *, int, int);

int main(){
	int N, M, i, cont = 0;
	scanf("%d %d", &N, &M);
	int pin[N];
	for (i = 0; i < N; i++)
		scanf("%d", &pin[i]);
	int *p1 = &pin[0], *p2 = &pin[1];

	while(check(&pin[0], N, M)){
		if (*p1 == M){
			p1++;
			p2++;
		}
		else{
			while (*p1 < M){
				cont++;
				*p1 = (*p1)+1; 
				*p2 = (*p2)+1;
			}
			while (*p1 > M){
				cont++;
				*p1 = (*p1)-1; 
				*p2 = (*p2)-1;
			}
		}
	}
	printf("%d\n", cont);
	return 0;
}

int check(int* arr, int N, int M){
	int i;
	for (i = 0; i < N; ++i){
		if (arr[i] == M)
			continue;
		else
			return 1;
	}
	return 0;
}
