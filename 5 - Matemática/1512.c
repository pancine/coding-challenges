#include <stdio.h>

int mult_ab(int , int);
int mdc(int, int);

int main(){
    int n, x, y;
    while (1){
        scanf("%d %d %d", &n, &x, &y);
        if (n+x+y == 0){break;}
        printf("%d\n", mult_ab(n, x) + mult_ab(n, y) - mult_ab(n, (x*y)/mdc(x,y)));
    }
}

int mult_ab(int x, int k){
    x = x - (x%k);
    return (x-k)/k + 1;
}

int mdc(int a, int b){
  if (b == 0)
      return a;
  return mdc(b, a%b);
}