/*
Melissa achou engraçada a frase que viu na camisa de um aluno do curso de Ciência da Computação da UERJ:
"Há 10 tipos de pessoas: as que entendem binário e as que não entendem"
Refletindo um pouco na piada, ela concluiu que os números escritos em base binária são os mais ambíguos 
dentre todas as bases. Com efeito, um número binário é uma representação numérica válida em qualquer 
base, o que não ocorre com representações numéricas não binárias. Por exemplo, a representação numérica 
"271" é inválida nas bases 2, 3, 4, 5, 6 e 7. Lembre que, em uma base b, um número N possui a representação 
numérica dkdk-1…d0 se 0 ≤ dk,dk-1,…,d0 < b e N = dkbk + dk-1bk-1 + … + d1b + d0
Melissa então se interessou pela seguinte questão: quantas sequências binárias podem ser representações 
numéricas válidas para certo número, considerando todas as possíveis bases de representação? Ajude Melissa 
a matar sua curiosidade, elaborando um programa para fazer as contas por ela.
Entrada:
A primeira linha da entrada é composta do inteiro 1 ≤ N < 104 que constitui o número de casos que Melissa 
gostaria de testar. Cada uma das próximas N linhas constitui de um número d, com 2 ≤ d ≤ 104, escrito em base decimal.
Saída:
Para cada número d informado, deve-se escrever em uma linha distinta o número de bases em que d é escrito em 
representação numérica binária.
*/

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
