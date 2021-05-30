//C99 20/09/2020
#include <stdio.h>
#include <math.h>

int main() {
	int casos, lado;
	double s, area, b;
	scanf("%d", &casos);
	while (casos--) {
		scanf("%d", &lado);
		b = lado / (2.0 * 0.587785252292473);
		s = (lado+b+b) / 2.0;
		area = sqrt(s * (s-lado) * (s-b) * (s-b));
		printf("%.3lf\n", 5.0 * area);
	}
	return 0;
}