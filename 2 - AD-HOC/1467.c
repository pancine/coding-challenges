#include <stdio.h>

int main(){
    int a[3];
    while(scanf("%d %d %d", &a[0], &a[1], &a[2]) != EOF){
        if (a[0]+a[1]+a[2] == 1) {
            for (int i=0; i<3; i++) {
                if (a[i] == 1) {
                    printf("%c\n",65+i);
                    break;
                }
            }
        }
        else if (a[0]+a[1]+a[2] == 2) {
            for (int i=0; i<3; i++) {
                if (a[i] == 0) {
                    printf("%c\n",65+i);
                    break;
                }
            }
        }
        else 
            printf("*\n");
    }
    return 0;
}