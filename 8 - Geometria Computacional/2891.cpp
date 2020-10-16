//C++17 14/10/2020
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


struct ponto { int x, y; };

ponto origem = {0,0};

bool sum(vector<ponto> vet);

bool comparatorx (ponto p1, ponto p2);

bool comparatory (ponto p1, ponto p2);

int SentidoPercurso(ponto p1, ponto p2, ponto p3);

double dist(ponto p2, ponto p1);

bool comparatorang(ponto p2, ponto p3);

void GrahamScan(vector<ponto> *vet, int num_pontos, vector<ponto> *gc);

double area(vector<ponto> vet);


int main()
{
    vector<ponto> pontos (5), atual, pol;
    int i, j;
    double actual_area = 0, max = 0;
    for (i = 0; i < 5; i++) {
        scanf("%d %d", &pontos[i].x, &pontos[i].y);
    }
    
    while (sum(pontos))
    {
        for (i = 0; i < 5; i++) 
        {
            for (j = i; j < i+4; j++) {
                atual.push_back(pontos[(j+1)%5]);
            }

            GrahamScan(&atual, atual.size(), &pol);
            if (pol.size() == 5)
            {
                actual_area = area(pol);
                
                if (actual_area > max) {
                    max = actual_area;
                }
            }

            atual.clear();
            pol.clear();
        }

        printf("%.0lf\n", max);

        for (i = 0; i < 5; i++) {
            scanf("%d %d", &pontos[i].x, &pontos[i].y);
        }
        actual_area = 0;
        max = 0;
    }
    return 0;
}


bool sum(vector<ponto> vet)
{
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += vet[i].x + vet[i].y;
    }
    return (sum > 0) ? 1: 0;
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


double area(vector<ponto> vet)
{
    double area = 0;
    for (int i = 0; i < vet.size() - 1; i++) {
        area += (vet[i].x*vet[i+1].y) - (vet[i].y*vet[i+1].x);
    }
    return area/2.0;
}
