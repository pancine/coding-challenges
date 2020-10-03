//C++17 02/10/2020
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto{double x,y;};
struct reta{double a,b,c;};

double area(ponto p1, ponto p2, ponto p3);
reta Pt_Rt(ponto p1, ponto p2);
double DistPt_Rt(reta r, ponto p);

int main() {
	int num_cerejas, i, j, k;
	double min = INFINITY, dpr, esq = 0, dir = 0;
	cin >> num_cerejas;

	while (num_cerejas) {
		min = INFINITY;
		ponto *coords = new ponto[num_cerejas];

		for (i = 0; i < num_cerejas; i++) 
			cin >> coords[i].x >> coords[i].y;

		for (i = 0; i < num_cerejas-1; i++) {
			for (j = i+1; j < num_cerejas; j++) {
				esq = 0.0;
				dir = 0.0;
				reta r = Pt_Rt(coords[i], coords[j]);
				for (int k = 0; k < num_cerejas; k++) {
                    if (k != i && k != j) {
						if (coords[i].y == coords[j].y) {
							dpr = fabs(coords[k].y - coords[i].y);
                            if (coords[k].y > coords[i].y)
                                esq += dpr;
							else
                                dir += dpr;
                        }
						else if (coords[i].x == coords[j].x){
							dpr = fabs(coords[k].x - coords[i].x);
							if (coords[k].x < coords[i].x) 
								esq += dpr;
							else
								dir += dpr;
						}
						else {
                            dpr = DistPt_Rt(r, coords[k]);
							if (area(coords[i], coords[j], coords[k]) > 0)
                                esq += dpr;
							else 
                                dir += dpr;
                        }
                    }
                }
				if (fabs(esq - dir) < min)
					min = fabs(esq - dir);
			}
		}
		cout << fixed << setprecision(3) << min << endl;
		delete[] coords;
		cin >> num_cerejas;
	}
	return 0;
}

double area(ponto p1, ponto p2, ponto p3) 
{
	return 0.5 * (p1.x*(p2.y-p3.y) - p2.x*(p1.y-p3.y) + p3.x*(p1.y-p2.y));
}

reta Pt_Rt(ponto p1, ponto p2) 
{
	reta r;
	if (p1.x == p2.x) {
		r.a = 1.0;
		r.b = 0.0;
		r.c = -p1.x;
	}
	else {
		r.a = -(p1.y - p2.y) / (p1.x - p2.x);
		r.b = 1.0;
		r.c = -(r.a*p1.x) - (r.b*p1.y);
	}
	return r;
}

double DistPt_Rt(reta r, ponto p) 
{
	double a2, x, y, c2;
	a2 = -1.0/r.a;
	c2 = -(p.y + a2*p.x);
	x = (c2 - r.c) / (r.a - a2);
	y = -(c2 + a2*x);
	return sqrt((y - p.y)*(y - p.y) + (x - p.x)*(x - p.x));
}