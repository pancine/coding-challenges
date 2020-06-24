//C99 19/03/2020
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	float n;
	int br, ale;
	scanf("%f", &n);
	while(n != 0){
		br = floor(n/90);
		ale = ceil(n/(90/7.0));
		printf("Brasil %d x Alemanha %d\n", br, ale);
		scanf("%f", &n);
	}
	return 0;
}
