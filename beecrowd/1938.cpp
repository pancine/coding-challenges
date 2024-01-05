//C++17 13/10/2020
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


struct ponto{ int x,y; };

bool comparator (ponto p1, ponto p2) { return (p1.x < p2.x); }


int main()
{
    int num_postes, i, j, cont = 0;
    double max_y_up, max_y_down;
    cin >> num_postes;
    
    vector<ponto> postes (num_postes);
    
    for (int i = 0; i < num_postes; i++) {
        cin >> postes[i].x >> postes[i].y;
    }

    sort(postes.begin(), postes.end(), comparator);

    for (i = 0; i < num_postes-1; i++) 
    {
        max_y_up = INFINITY;
        max_y_down = -INFINITY;

        for (j = i+1; j < num_postes; j++)
        {
            if (postes[j].y > postes[i].y && postes[j].y < max_y_up) 
            {
                max_y_up = postes[j].y;
                cont++;
            }
            else if(postes[j].y < postes[i].y && postes[j].y > max_y_down)
            {
                max_y_down = postes[j].y;
                cont++;
            }
        }
    }
    
    cout << cont << endl;

    return 0;
}