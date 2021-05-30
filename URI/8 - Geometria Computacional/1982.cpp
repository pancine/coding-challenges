//C++17 14/10/2020
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


struct ponto { int x, y; };

ponto origem = {0,0};

bool comparatorx (ponto p1, ponto p2);

bool comparatory (ponto p1, ponto p2);

int SentidoPercurso(ponto p1, ponto p2, ponto p3);

double dist(ponto p2, ponto p1);

bool comparatorang(ponto p2, ponto p3);

void GrahamScan(vector<ponto> *vet, int num_pontos, vector<ponto> *gc);


int main()
{
    ponto temp;
    int n, i;
    double perimeter = 0;
    scanf("%d", &n);

    while (n > 0)
    {
        vector<ponto> computers (n), pol;

        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &computers[i].x, &computers[i].y);
        }

        GrahamScan(&computers, computers.size(), &pol);

        for (i = 0; i < pol.size()-1; i++)
        {
            perimeter += sqrt(dist(pol[i], pol[i+1]));
        }

        printf("Tera que comprar uma fita de tamanho %.2lf.\n", perimeter);
        scanf("%d", &n);
        perimeter = 0;
    }
    return 0;
}


bool comparatorx (ponto p1, ponto p2) 
{
    return (p1.x < p2.x);
}


bool comparatory (ponto p1, ponto p2) 
{

    return (p1.y < p2.y); 
}


int SentidoPercurso(ponto p1, ponto p2, ponto p3)
{
    long long a, b, c, d;

    a = p2.x - p1.x;
    b = p3.y - p1.y;
    c = p3.x - p1.x;
    d = p2.y - p1.y;
    a = a*b - c*d;
   
    if (a < 0) {
       return -1;
    }
    else {
        return (a > 0);
    }
}


double dist(ponto p2, ponto p1)
{
    return ((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}


bool comparatorang(ponto p2, ponto p3)
{
    if (SentidoPercurso(origem,p2,p3) == 1 || (SentidoPercurso(origem,p2,p3) == 0 && dist(p2,origem) < dist(p3,origem))) {
        return 1;
    }
    return 0;
}


void GrahamScan(vector<ponto> *vet, int num_pontos, vector<ponto> *gc)
{
    int num = 0;

    sort((*vet).begin(), (*vet).end(), comparatory);

    while ((*vet)[num].y == (*vet)[0].y) num++;

    sort((*vet).begin(), (*vet).begin()+num, comparatorx);

    origem = { (*vet)[0].x, (*vet)[0].y };
    
    sort((*vet).begin()+1, (*vet).end(), comparatorang);
    
    (*gc).push_back((*vet)[0]);

    for (int i = 1; i < num_pontos; i++) 
    {
        if ((*gc).size() < 2) {
            (*gc).push_back((*vet)[i]);
        }
        else {
            while ((*gc).size() > 1 && SentidoPercurso((*gc)[(*gc).size()-2], (*gc)[(*gc).size()-1], (*vet)[i]) != 1) {
                (*gc).pop_back();
            }
            (*gc).push_back((*vet)[i]);
        }
    }
    (*gc).push_back((*vet)[0]);
}

