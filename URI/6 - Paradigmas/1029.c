//C99 06/11/2019
#include <stdlib.h>
#include <stdio.h>

int fib(int n);
int count = -1;

int main(){
    int n, N, i = 0;
    scanf("%d", &N);
    for(i; i < N; i++){
        count = 0;
        scanf("%d", &n);
        printf("fib(%d) = %d calls = %d\n", n, count - 1, fib(n));    
    }
    return 0;
}

int fib(int n){
    count++;
    if(n < 2) return n;
    else return fib(n-1) + fib(n-2);
}
