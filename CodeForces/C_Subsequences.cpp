#include <iostream>
using namespace std;

#define N 110000
#define ll long long

void add(ll *a, int x, ll v) {
    for (; x <= n; x += x & -x) a[x] += v;
}

ll query(ll *a, ll x) {
    ll v = 0;
    for (; x; x -= x & -x) v += a[x];
    return v;
}

int n, k;
ll a[11][N];
int tmp[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &tmp[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = k - 1; j >= 0; j--) {
            add(a[j + 1], tmp[i], query(a[j], tmp[i]));
        }
        add(a[0], tmp[i], 1);
    }

    printf("%lld\n", query(a[k], n));
    return 0;
}