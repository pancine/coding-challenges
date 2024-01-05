#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define TOLERANCE 1e-5

int main() {
    int test_cases, number_of_people, ml, b, B, H;
    double hi, hf, hx, bx, lx;

    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        cin >> number_of_people >> ml;
        cin >> b >> B >> H;
        hi = 0; hf = H;

        while (true) {
            hx = (hf + hi) / 2;
            bx = b + (B - b) * hx / H;
            lx = number_of_people * M_PI * hx * (b * b + b * bx + bx * bx) / 3;

            if (fabs(lx - ml) < TOLERANCE)
                break;
            else if (ml < lx)
                hf = hx;
            else
                hi = hx;
        }

        cout << fixed << setprecision(2) << hx << endl;
    }

    return 0;
}
