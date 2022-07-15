#include <iostream>
#include <vector>

typedef long long int lli;

typedef struct {
    lli sum;
    lli lazySum;
} node;

std::vector<node> segmentArray;

void refresh(int position, int start, int end) {
    if (segmentArray[position].lazySum == 0) {
        return;
    }

    lli num = segmentArray[position].lazySum;
    segmentArray[position].lazySum = 0;
    segmentArray[position].sum += (end - start + 1) * num;

    if (start == end) {
        return;
    }

    int l = 2 * position;
    int r = (2 * position) + 1;

    segmentArray[l].lazySum += num;
    segmentArray[r].lazySum += num;
}

void update(int position, int start, int end, int p, int q, lli value) {
    refresh(position, start, end);

    if (q < start || p > end) {
        return;
    }

    if (p <= start && end <= q) {
        segmentArray[position].lazySum += value;
        refresh(position, start, end);
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * position;
    int r = (2 * position) + 1;

    update(l, start, m, p, q, value);
    update(r, m + 1, end, p, q, value);

    segmentArray[position].sum = segmentArray[l].sum + segmentArray[r].sum;
}

lli query(int position, int start, int end, int p, int q) {
    refresh(position, start, end);

    if (q < start || p > end) {
        return 0;
    }

    if (p <= start && end <= q) {
        return segmentArray[position].sum;
    }

    int middle = (start + end) / 2;
    int l = 2 * position;
    int r = (2 * position) + 1;

    lli x = query(l, start, middle, p, q);
    lli y = query(r, middle + 1, end, p, q);
    return x + y;
}

int main() {
    int arraySize, numberOfOperations, operationType, l, r;
    lli value;

    scanf("%i %i", &arraySize, &numberOfOperations);
    segmentArray.resize(arraySize * 4);

    for (int i = 0; i < numberOfOperations; i++) {
        scanf("%d", &operationType);

        if (operationType == 1) {
            scanf("%i %i %lli", &l, &r, &value);
            update(1, 1, arraySize, l + 1, r, value);
        } else {
            scanf("%i %i", &l, &r);
            printf("%lli\n", query(1, 1, arraySize, l + 1, r));
        }
    }

    return 0;
}
