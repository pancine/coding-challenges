#include <iostream>
#include <vector>
using namespace std;

int main() {
    int test_cases, friends, count, sum;
    vector<int> numbers(0);

    cin >> test_cases;

    while (test_cases--) {
        sum = 0.0;
        cin >> friends;
        numbers.resize(friends);
        for (int i = 0; i < friends; i++) {
            cin >> numbers[i];
            sum += numbers[i];
        }
        if (sum % friends != 0) {
            cout << -1 << endl;
        } else {
            count = 0;
            for (int i = 0; i < friends; i++) {
                if (numbers[i] > sum / friends) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}