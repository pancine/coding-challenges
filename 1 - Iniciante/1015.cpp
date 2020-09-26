#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double x[2], y[2];
	cin >> x[0] >> y[0];
	cin >> x[1] >> y[1];
	cout << fixed << setprecision(4) << sqrt(pow(y[1]-y[0],2.0) + pow(x[1]-x[0],2.0)) << endl;
	return 0;
}