//C++17 03/10/2020
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto { int xi,yi,xf,yf; };
struct reta { double a,b,c; };

struct reta Pt_Rt(int x1, int y1, int x2, int y2);
double DistPt_Rt(int x, int y, struct reta r);
double dist(int x1, int y1, int x2, int y2);

int main() {
    int aletas, x_haste, altura_hastes;
    struct ponto p[1000];
	struct reta r;
	double min, buraco;

    while (cin >> aletas){
		min = 10000;
        cin >> x_haste >> altura_hastes;
        
		for (int i = 0; i < aletas; i++) {
            cin >> p[i].yi >> p[i].xf >> p[i].yf;
			if ((i+1)%2 != 0) {
                p[i].xi = 0;
				
				buraco = x_haste - p[i].xf;
				if (buraco < min)
					min = buraco;
				
				if (i > 0){
					if (p[i-1].xf <= p[i].xf){
						r = Pt_Rt(p[i].xi, p[i].yi, p[i].xf, p[i].yf);
						buraco = DistPt_Rt(p[i-1].xf, p[i-1].yf, r);
					}
					else
						buraco = dist(p[i-1].xf, p[i-1].yf, p[i].xf, p[i].yf);

					if (buraco < min)
						min = buraco;
				}
				
            }
            else {
                p[i].xi = x_haste;

				buraco = p[i].xf;
				if (buraco < min)
					min = buraco;

				if (p[i-1].xf >= p[i].xf){
					r = Pt_Rt(p[i].xi, p[i].yi, p[i].xf, p[i].yf);
					buraco = DistPt_Rt(p[i-1].xf, p[i-1].yf, r);
				}
				else
					buraco = dist(p[i-1].xf, p[i-1].yf, p[i].xf, p[i].yf);

				if (buraco < min)
					min = buraco;
            }
        }
        cout << fixed << setprecision(2) << min << endl;
    }
    return 0;
}

struct reta Pt_Rt(int x1, int y1, int x2, int y2)
{
	struct reta r;
	if (x1 == x2) {
		r.a = 1.0;
		r.b = 0.0;
		r.c = -x1;
	}
	else {
		r.a = -(y1 - y2)*1.0 / (x1 - x2);
		r.b = 1.0;
		r.c = -(r.a*x1) - (r.b*y1);
	}
	return r;
}

double DistPt_Rt(int x, int y, struct reta r) {
	double a2 = -1.0 / r.a, c2 = -a2 * x - y, xr = -(r.c - c2) / (r.a - a2), yr = -c2 - a2 * (xr);

	return sqrt(pow(xr - x, 2) + pow(yr - y, 2));
}

double dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}