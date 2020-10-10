#include <stdio.h>

int division(int, int);

int main(){
	int n, i, cont = 0, num, base = 2, numflag;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		numflag = num;
		while(numflag >= base){
			while(num != 0){
				if(num%base == 1 || num%base == 0){
					num/=base;
					if(num == 0){
						cont++;
					}
				}else{
					break;
				}
			}
			base++;
			num = numflag;
		}
		printf("%d\n", cont);
		cont = 0;
		base = 2;
	}
    return 0;
}
