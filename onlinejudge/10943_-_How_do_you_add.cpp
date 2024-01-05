#include <iostream>
using namespace std;

int T[101][101];

int main() {
    int n, k;

    for (int i = 0; i < 101; i++) {
        T[0][i] = 1;
        T[i][0] = 0;
    }

    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            T[i][j] = ((T[i][j - 1] % 1000000) + (T[i - 1][j] % 1000000) % 1000000);
        }
    }

    while (cin >> n >> k, n != 0 && k != 0) {
        cout << T[n][k] % 1000000 << endl;
    }

    return 0;
}
