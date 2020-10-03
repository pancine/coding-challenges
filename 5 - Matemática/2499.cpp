//C++17 26/09/2020
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	long long int s, n, m, c[3];
	cin >> s >> n >> m;
	
	while (s+n+m) {
		cin >> c[0] >> c[1] >> c[2];
		if (c[2] < c[1]) {
			long long int temp = c[2];
			c[2] = c[1];
			c[1] = temp;
		}
		cout << (s *(c[0]*(c[2]-c[1]))) / ((n+1)*(m+1)) << endl;
		cin >> s >> n >> m;
	}
	return 0;
}