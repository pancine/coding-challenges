#include <stdio.h>
using namespace std;

#define ll long long

const int MAX = 100000;
ll values[MAX];
ll segmentTree[MAX * 4];

void build_segmented_tree(ll pos, ll begin, ll end) {
    if (begin == end) {
        segmentTree[pos] = values[begin];
        return;
    }

    ll m = (begin + end) / 2;
    ll left = (pos * 2) + 1;
    ll right = (pos * 2) + 2;

    build_segmented_tree(left, begin, m);
    build_segmented_tree(right, m + 1, end);

    segmentTree[pos] = segmentTree[left] + segmentTree[right];
}

ll query(ll pos, ll begin, ll end, ll p, ll q) {
    if (q < begin || end < p) {
        return 0;
    }
    if (p <= begin && end <= q) {
        return segmentTree[pos];
    }

    ll m = (begin + end) / 2;
    ll left = (pos * 2) + 1;
    ll right = (pos * 2) + 2;

    return query(left, begin, m, p, q) + query(right, m + 1, end, p, q);
}

void update_segmented_tree(ll pos, ll begin, ll end, ll index, ll value) {
    if (index < begin || index > end) {
        return;
    }
    if (begin == end) {
        segmentTree[pos] = value;
        return;
    }

    ll m = (begin + end) / 2;
    ll left = (pos * 2) + 1;
    ll right = (pos * 2) + 2;

    update_segmented_tree(left, begin, m, index, value);
    update_segmented_tree(right, m + 1, end, index, value);

    segmentTree[pos] = segmentTree[left] + segmentTree[right];
}

int main() {
    ll arraySize, numberOfOperations, operationType, value1, value2;
    scanf("%lli %lli", &arraySize, &numberOfOperations);

    for (ll i = 0; i < arraySize; i++) {
        scanf("%lli", &value1);
        values[i] = value1;
    }

    build_segmented_tree(0, 0, arraySize - 1);

    for (ll i = 0; i < numberOfOperations; i++) {
        scanf("%lli %lli %lli", &operationType, &value1, &value2);
        if (operationType == 1) {
            update_segmented_tree(0, 0, arraySize - 1, value1, value2);
        } else {
            printf("%lli\n", query(0, 0, arraySize - 1, value1, value2 - 1));
        }
    }

    return 0;
}