//C99 13/05/2020
#include <stdio.h>

int check(int *, int *);

int main()
{
    int x[4], y[4];
    scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
    scanf("%d %d %d %d", &x[2], &y[2], &x[3], &y[3]);
    if (check(x, y))
        printf("1\n");
    else
        printf("0\n");
    return 0;
}

int check(int *x, int *y)
{
    int flagx = 0, flagy = 0;
    for (int i = x[2]; i <= x[3]; i++)
    {
        if (x[0] <= i && i <= x[1])
            flagx = 1;
    }
    for (int i = y[2]; i <= y[3]; i++)
    {
        if (y[0] <= i && i <= y[1])
            flagy = 1;
    }
    if (flagx && flagy)
        return 1;
    
    return 0;
}