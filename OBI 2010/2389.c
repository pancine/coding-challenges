//C99 26/06/2020
#include <stdio.h>

int main()
{
    int arvores, cont = 0;
    scanf("%d", &arvores);
    for (int i = 2; i*i <= arvores; i++) {
        if ( (arvores + i - 1) % (2*i - 1) == 0 && i <= (arvores + i - 1) / (2*i - 1) )
        {
     	   cont++;
    	}
    }
    printf("%d\n", cont);
    return 0;
}