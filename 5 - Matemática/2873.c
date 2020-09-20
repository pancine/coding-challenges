//C99 20/09/2020
#include <stdio.h>

int main() {
	double a, b, c, d, h;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

	while (a+b+c+d > 0) {
		h = ((a * 0.5 + b) * c) / d;
		printf("%.5lf\n", h);
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	}

	return 0;
}