//C99 02/08/2020
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main(){
    int n, d[3], d2[3], flag;
    scanf("%d",&n);
    
    for (int i=0; i<n; i++) {
        scanf("%d %d %d %d %d %d", &d[0], &d[1], &d[2], &d2[0], &d2[1], &d2[2]);
        qsort(d, 3, sizeof(int), compare);
        qsort(d2, 3, sizeof(int), compare);
        flag = 0;
        if (d2[1] > d[0] && d2[2] > d[1])
            flag = 1;
        if (d[1] > d2[0] && d[2] > d2[1]) {
            if (flag)
                flag = 3;
            else
                flag = 2;
        }
        printf("%d\n", flag);
    }
    return 0;
}