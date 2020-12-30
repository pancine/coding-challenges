//C++17 14/10/2020
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct ponto { int x,y; };

ponto origem = {0,0};

int miny;

bool comparatorx (ponto p1, ponto p2);

bool comparatory (ponto p1, ponto p2);

int SentidoPercurso(ponto p1, ponto p2, ponto p3);

double dist(ponto p2, ponto p1);

bool comparatorang(ponto p2, ponto p3);

int GrahamScan(vector<ponto> *vet, int num_pontos, vector<ponto> *gc);

int pontoNoSegmento(ponto p0, ponto p1, ponto p2);

int pontoInteriorPoligonoConvexo(vector<ponto> pol, int n, ponto q);


int main()
{
    vector<ponto> cop (4);
    ponto student;

    for (int i = 0; i < 4; i++) {
        cin >> cop[i].x >> cop[i].y;
    }
    cin >> student.x >> student.y;

    if (SentidoPercurso(cop[0], cop[1], cop[2]) == 0 && SentidoPercurso(cop[1], cop[2], cop[3]) == 0) {
        cout << " O>\n<| \n/ >\n";
    }
    else
    {
        vector<ponto> gc;
        int num_vertices = GrahamScan(&cop, 4, &gc);
        
        if (pontoInteriorPoligonoConvexo(gc, num_vertices-1, student)) {
            cout << "\\O/\n | \n/ \\\n";
        }
        else {
            cout << " O>\n<| \n/ >\n";
        }
    }

    return 0;
}


bool comparatorx (ponto p1, ponto p2) 
{
    return (p1.x < p2.x && p1.y == miny);
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


int GrahamScan(vector<ponto> *vet, int num_pontos, vector<ponto> *gc)
{
    int num = 1;

    sort((*vet).begin(), (*vet).end(), comparatory);

    while ((*vet)[num].y == (*vet)[0].y) num++;

    sort((*vet).begin(), (*vet).begin()+num, comparatorx);

    origem = { (*vet)[0].x, (*vet)[0].y };
    
    sort((*vet).begin()+1, (*vet).end(), comparatorang);
    
    gc->push_back((*vet)[0]);

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

    return (*gc).size();
}


int pontoNoSegmento(ponto p0, ponto p1, ponto p2)
{
    return SentidoPercurso(p0, p1, p2) == 0 &&
           p0.x >= min(p1.x, p2.x) && p0.x <= max(p1.x, p2.x) &&
           p0.y >= min(p1.y, p2.y) && p0.y <= max(p1.y, p2.y);
}


int pontoInteriorPoligonoConvexo(vector<ponto> pol, int n, ponto q)
{
	int t, t1, i; 
    
	pol[n] = pol[0];
	
    t = SentidoPercurso(q, pol[n-1], pol[0]);
	
    if (t==0) {
	    return pontoNoSegmento(q, pol[n-1], pol[0]);
    }

    for (i=1; i<=n-1; i++) 
    {
        t1 = SentidoPercurso(q, pol[i-1], pol[i]);
		if (t1==0) {
	    	return pontoNoSegmento(q, pol[i-1], pol[i]);        
        }
        if (t != t1) {
			return 0;
        }
	}
	return 1;
}