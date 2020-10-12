//C++17 12/10/2020
#include <iostream>
#include <stdio.h>

using namespace std;


typedef struct { double x, y; }ponto;

double dist(ponto p1, ponto p2);


int main()
{
    int n;
    double tempo;
    ponto inicio, temp;
    bool flag = true;

    scanf("%lf %lf %d", &inicio.x, &inicio.y, &n);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf %lf %lf", &temp.x, &temp.y, &tempo);

        if (tempo * tempo > dist(temp, inicio)) {
            if (flag) {
                printf("%d", i);
                flag = false;
            }
            else {
                printf(" %d", i);
            }
        }
    }

    if (flag) {
        printf("-1\n");
    }
    else {
        printf("\n");
    }
    
    return 0;
}


double dist(ponto p1, ponto p2)
{
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}