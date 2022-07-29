#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define SOLUTION 7
#define VISITED 9
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

bool solved = false;
int n;
vector<vector<int>> table;
vector<pair<int, int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0,  -1}, {0,  1}, {1,  -1}, {1,  0}, {1,  1},
};

void solve(int x, int y) {
    if (solved) {
        return;
    }

    if (table[x][y] == SOLUTION) {
        cout << "YES" << endl;
        solved = true;
        return;
    }

    table[x][y] = VISITED;

    for (pair<int, int> direction : directions) {
        int auxX = x + direction.first, auxY = y + direction.second;
        if (auxY >= 0 and auxY < n and auxX >= 0 and auxX < n and table[auxX][auxY] != 1 && table[auxX][auxY] != 9) {
            solve(auxX, auxY);
        }
    }
}

int main() {
    ibs; cti;

    int ax, ay, bx, by, cx, cy;
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    table = vector<vector<int>>(n, vector<int>(n, 0));
    table[cx - 1][cy - 1] = SOLUTION;

    for (int i = 0; i < n; i++) table[i][ay - 1] = 1;
    for (int i = 0; i < n; i++) table[ax - 1][i] = 1;
    for (int i = ax - 1, j = ay - 1; i < n and j < n; i++, j++) table[i][j] = 1;
    for (int i = ax - 1, j = ay - 1; i >= 0 and j >= 0; i--, j--) table[i][j] = 1;
    for (int i = ax - 1, j = ay - 1; i < n and j >= 0; i++, j--) table[i][j] = 1;
    for (int i = ax - 1, j = ay - 1; i >= 0 and j < n; i--, j++) table[i][j] = 1;

    solve(bx - 1, by - 1);

    if (!solved) {
        cout << "NO" << endl;
    }

    return 0;
}