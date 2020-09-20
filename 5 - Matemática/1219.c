//C99 20/09/2020
#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	double area, s, r, R, PI = acos(-1);
	while (scanf("%d %d %d", &a, &b, &c) != EOF) {
		s = (a+b+c) / 2.0;
		area = sqrt(s * (s-a) * (s-b) * (s-c));
		r = area / s;
		R = (a*b*c) / (4.0 * area);
		printf("%.4lf %.4lf %.4lf\n", (PI*R*R)-area, area-(PI*r*r), PI*r*r);
	}
	return 0;
}