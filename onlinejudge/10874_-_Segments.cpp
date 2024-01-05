#include <iostream>
using namespace std;

int me[20001];
int md[20001];

int main() {
    int n, l1, l2, r1, r2;
    cin >> n;

    while (n != 0) {
        cin >> l1 >> r1;

        me[0] = 2 * r1 - l1 - 1;
        md[0] = r1 - 1;

        for (int i = 1; i < n; i++) {
            cin >> l2 >> r2;

            me[i] = min(me[i - 1] + abs(l1 - r2) + r2 - l2, md[i - 1] + abs(r1 - r2) + r2 - l2);
            md[i] = min(me[i - 1] + abs(l1 - l2) + r2 - l2, md[i - 1] + abs(r1 - l2) + r2 - l2);

            if (i != n - 1) {
                l1 = l2;
                r1 = r2;
            }
        }

        cout << min(me[n - 2] + abs(l1 - l2) + n - l2, md[n - 2] + abs(r1 - l2) + n - l2) + n - 1 << endl;
        cin >> n;
    }

    return 0;
}
