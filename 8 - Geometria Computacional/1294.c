//C99 21/09/2020
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void raizes(double *r, double L, double W);
double min(double a, double b);

int main() {
	double largura, comprimento;
	double *x1x2 = malloc(sizeof(double) * 2);
	while (scanf("%lf %lf", &largura, &comprimento) != EOF) {
		raizes(x1x2, largura, comprimento);
		if (((largura-2.0*x1x2[1])*(comprimento-2.0*x1x2[1])*(x1x2[1])) <= 0.0) {
			printf("%.3lf 0.000 %.3lf\n", x1x2[0], min(largura, comprimento)/2.0);
		}
		else {
			printf("%.3lf 0.000 %.3lf\n", x1x2[0], x1x2[1]);
		}
	}
	return 0;
}

void raizes(double *r, double L, double W) {
	double a = 12.0, b = -4.0 * (L+W), c = L*W;
	r[0] = (-b - sqrt(b*b - 4.0*a*c)) / (2.0*a);
	r[1] = (-b + sqrt(b*b - 4.0*a*c)) / (2.0*a);
}

double min(double a, double b) {
	if (a < b) {
		return a;
	}
	return b;
}