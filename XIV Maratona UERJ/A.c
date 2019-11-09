/*
Uma empresa quer mandar um envelope para obter uma resposta de um cliente e quer saber se é possível 
colocar esse envelope dentro de outro. Ambos envelopes são retangulares e um só pode ser colocado 
dentro do outro se as dimensões forem ambas menores. Dadas as dimensões dos dois envelopes, responda
se é possível ou não colocar o primeiro dentro do segundo.
Entrada:
A entrada consiste de uma série de testes. A primeira linha contém um único inteiro indicando o 
número n (1 ≤ n ≤ 20) de casos de testes. A seguir vêm n linhas contendo, cada uma, um caso de teste. 
Cada caso de teste se compõe de 4 inteiros: os dois primeiros são as dimensões do envelope que deve 
ir dentro e os dois últimos, a dimensão do envelope principal.
Saída:
Para cada caso de teste imprima, em uma linha:
. 'S' se for possível colocar o primeiro envelope dentro do segundo, ou
. 'N', caso contrário.
*/
#include <stdio.h>
int main(){
    int n, l1, h1, l2, h2, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d %d %d", &l1, &h1, &l2, &h2);
        if((l1 < l2 && h1 < h2) || (l1 < h2 && h1 < l2)){
            printf("S\n");
        }else{
            printf("N\n");
        }    
    }
    return 0;
}