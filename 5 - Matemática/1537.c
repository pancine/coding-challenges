//C99 01/08/2020
#include <stdio.h>

long long int arr(int);

int main(){
    long long int x;
    scanf("%lld", &x);
    while(x != 0){
        printf("%lld\n", arr(x));
        scanf("%lld", &x);
    }
}

long long int arr(int x){
    if (x == 3){
        return 1;
    }
    else
        return (x*arr(x-1)) % 1000000009;
}