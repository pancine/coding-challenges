#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define TOLERANCE 1e-10

int main() {
    double a, b, ratio, radius, angle, arc, l, w, min, max;
    int actual_case = 1;

    while (scanf("%lf : %lf", &a, &b) == 2) {
        min = 0;
        max = 400;

        while (abs(max - min) > TOLERANCE) {
            ratio = b / a;
            l = (min + max) / 2;
            w = ratio * l;
            radius = sqrt((l / 2) * (l / 2) + (w / 2) * (w / 2));
            angle = acos((2 * radius * radius - w * w) / (2 * radius * radius)) * 180 / M_PI;
            arc = 2 * M_PI * radius * (angle / 360);

            if (2 * arc + 2 * l > 400)
                max = l;
            else
                min = l;
        }

        printf("Case %d: %.10lf %.10lf\n", actual_case++, l, w);
    }
    return 0;
}