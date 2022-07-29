#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

int main() {
    cti; ibs;
    int k;
    cin >> k;

    if (k == 1) {
        cout << "YES\n2 1\n1 2";
    }
    else if (k % 2 == 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << 2 * (k + 2) << " " << k * (k + 2) << endl;

        for (int i = 1;i <= k + 2;i++) {
            for (int j = i + 1;j <= k + 2;j++) {
                if ((j % 2 == 1 or j == 2) and (j == i + 1))continue;

                cout << i << " " << j << endl;
                cout << i + k + 2 << " " << j + k + 2 << endl;
            }
        }

        cout << 2 << " " << k + 4 << endl;
    }

    return 0;
}