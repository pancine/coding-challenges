#include <algorithm>
#include <iostream>
using namespace std;

bool is_solution(int, int, int);

int d[601];

int main() {
    int n, k;

    while (cin >> n >> k) {
        n++;

        for (int i = 0; i < n; i++) cin >> d[i];

        int sum = 0;
        if (k == 0) {
            for (int i = 0; i < n; i++) sum += d[i];
            cout << sum << endl;
            continue;
        }

        for (int i = 0; i < n; i++) sum += d[i];

        int l1 = 0, l2 = INT32_MAX;

        while (l1 <= l2) {
            int mid = (l1 + l2) / 2;

            if (is_solution(mid, n, k))
                l2 = mid - 1;
            else
                l1 = mid + 1;
        }

        cout << l2 + 1 << endl;
    }

    return 0;
}

bool is_solution(int mid, int n, int k) {
    int actual_sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] > mid)
            return false;
        else if (actual_sum + d[i] > mid)
            actual_sum = d[i], count++;
        else
            actual_sum += d[i];
    }

    if (actual_sum) {
        count++;
    }

    return count <= k + 1;
}
