//C99 09/09/2020
#include <stdio.h>
#include <math.h>

double distAB(int xa, int ya, int xi, int yi);
int SCM(int n, double *acA, double *acB);
double BuscaBin(double *T, double ini, double fim, double x);
void quicksort(double *array, double *arr2, int ini, int fim);
int particao(double *array, double *arr2, int ini, int fim);

int main() {
	double n, xa, xb, xc, yc, a, b, c, acA[101], acB[101];
	scanf("%lf %lf %lf", &n, &xa, &xb);
	
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf", &xc, &yc);
		a = distAB(xb, 0, xc, yc);
		b = distAB(xa, 0, xc, yc);
		c = xb - xa;
		acA[i] = acos((b*b + c*c - a*a)/(2*b*c));
		acB[i] = acos((a*a + c*c - b*b)/(2*a*c));
	}
	quicksort(acA, acB, 1, n);
	printf("%d\n", SCM(n, acA, acB));

	return 0;
}

double distAB(int xa, int ya, int xi, int yi) {
	double d = sqrt(((yi-ya)*(yi-ya)) + ((xi-xa)*(xi-xa)));
	return d;
}

int SCM(int n, double *acA, double *acB) {
	int k = 1, j;
	double T[n], O[n];
	T[1] = acB[1];
	O[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (acB[i] > T[k] || acA[i] == acA[i-1]) {
			k++;
			T[k] = acB[i];
			O[i] = k;
		}
		else {
			j = BuscaBin(T, 1, k, acB[i]);
			T[j] = acB[i];
			O[i] = j;
		}
	}
	return k;
}

double BuscaBin(double *T, double ini, double fim, double x) { 
	int m;
    if (ini > fim)
        return ini;
    else {
        m = (ini + fim)/2;
        if(T[m] < x) {
            return BuscaBin(T, m+1, fim, x);
        }
        else{
        	return BuscaBin(T, ini, m-1, x);
        }
    }
}

void quicksort(double *array, double *arr2, int ini, int fim) { 
    if (ini < fim) {
        int pi = particao(array, arr2, ini, fim); 
        quicksort(array, arr2, ini, pi - 1); 
        quicksort(array, arr2, pi + 1, fim); 
    }
}

int particao(double *array, double *arr2, int ini, int fim) { 
    double pivot = array[fim], temp;
    int i = (ini - 1);
  
    for (int j = ini; j < fim; j++) { 
        if (array[j] < pivot) { 
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            temp = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp;
        } 
    }

    temp = array[i+1];
    array[i+1] = array[fim];
    array[fim] = temp;
    temp = arr2[i+1];
    arr2[i+1] = arr2[fim];
    arr2[fim] = temp;

    return (i + 1); 
} 