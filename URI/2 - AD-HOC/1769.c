//C99 19/03/2020
#include <stdio.h>
#include <string.h>

int main()
{
	int b1,b2;
	char cpf[20];
	while(scanf(" %s", cpf) != EOF){
		b1 = (((cpf[0] - '0')+((cpf[1] - '0')*2)+((cpf[2] - '0')*3)+((cpf[4] - '0')*4)+((cpf[5] - '0')*5)+((cpf[6] - '0')*6)+((cpf[8] - '0')*7)+((cpf[9] - '0')*8)+((cpf[10] - '0')*9))%11);
		b2 = ((((cpf[0] - '0')*9)+((cpf[1] - '0')*8)+((cpf[2] - '0')*7)+((cpf[4] - '0')*6)+((cpf[5] - '0')*5)+((cpf[6] - '0')*4)+((cpf[8] - '0')*3)+((cpf[9] - '0')*2)+(cpf[10] - '0'))%11);
		if (b1 == 10)	b1 = 0;
		if (b2 == 10)	b2 = 0;
		if (b1 == (cpf[12]-'0')){
			if (b2 == (cpf[13] - '0'))
				printf("CPF valido\n");
			else
			    printf("CPF invalido\n");
		}
		else
		    printf("CPF invalido\n");
	}
	return 0;
}
