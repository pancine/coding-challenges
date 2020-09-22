//C99 20/09/2020
#include <stdio.h>
#include <math.h>

void swap(double *, double *);
double min(double, double);

int main() {
	double lado, lado2, raio, volume, volume2, PI = acos(-1);
	scanf("%lf %lf", &lado, &lado2);

	while (lado + lado2 > 0) {
		if (lado2 > lado)
			swap(&lado2, &lado);
		
		raio = lado2 / (2.0 * PI);
		volume = PI * raio * raio * (lado - 2.0 * raio);

		raio = min(lado2/2.0, lado/(2.0  + 2.0*PI));
		volume2 = PI * raio * raio * lado2;

		if (volume > volume2) 
			printf("%.3lf\n", volume);
		else
			printf("%.3lf\n", volume2);

		scanf("%lf %lf", &lado, &lado2);
	}
	return 0;
}

void swap(double *a, double *b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

double min(double a, double b) {
	if (a < b) {
		return a;
	}
	return b;
}