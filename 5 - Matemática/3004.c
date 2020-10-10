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