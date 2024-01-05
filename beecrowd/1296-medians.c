//C99 20/09/2020
#include <stdio.h>
#include <math.h>

int main() {
	double m[3], area, s;
	while (scanf("%lf %lf %lf", &m[0], &m[1], &m[2]) != EOF) {
		s = (m[0]+m[1]+m[2]) * 0.5;
		area = (1.33333333333 * sqrt(s * (s-m[0]) * (s-m[1]) *(s-m[2])));
		for (int i = 0; i < 3; i++) {
			if (s-m[i] <= 0) {
				area = -1.000;
				break;
			}
		}
		printf("%.3lf\n", area);
	}
	return 0;
}