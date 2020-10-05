//C++17 04/10/2020
#include <iostream>

using namespace std;

int main() {
    int n, xi, xf, yi, yf, i, j, x, y, num = 0;
    bool quadro[100][100];
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            quadro[i][j] = false;
        }
    }

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> xi >> xf >> yi >> yf;
        for (x = xi; x < xf; x++){
            for (y = yi; y < yf; y++){
                quadro[x][y] = true;
            }
        }
    }

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (quadro[i][j])
                num++;
        }
    }

    cout << num << endl;
    return 0;
}