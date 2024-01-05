#include <iostream>
#include <vector>
using namespace std;

#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"
#define MAX 1001

int main() {
    cti; ibs;
    int t, w, n, depth, gold;
    bool first = true;

    vector<pair<int, int>> backpack(31);

    while (cin >> t >> w) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> depth >> gold;
            backpack[i] = pair<int, int>(3 * w * depth, gold);
        }

        vector<pair<int, int>> dp(MAX);
        vector<vector<bool>> is_solved(MAX, vector<bool>(31, false));
        vector<int> counter(MAX, 0);

        dp[0].first = 0;
        dp[0].second = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = t; j >= backpack[i].first; j--) {
                if (dp[j].second < dp[j - backpack[i].first].second + backpack[i].second) {
                    dp[j].second = dp[j - backpack[i].first].second + backpack[i].second;
                    counter[j] = counter[j - backpack[i].first] + 1;
                    is_solved[j][i] = true;
                }
            }
        }

        if (!first) {
            cout << endl;
        }
        first = false;

        cout << dp[t].second << endl;
        cout << counter[t] << endl;

        for (int i = 0, j = t; i < n; i++) {
            if (is_solved[j][i]) {
                cout << backpack[i].first / w / 3 << " " << backpack[i].second << endl;
                j -= backpack[i].first;
            }
        }
    }
    return 0;
}