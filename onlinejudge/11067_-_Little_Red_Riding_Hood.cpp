#include <iostream>
using namespace std;

#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);

int map[101][101];
int wmap[101][101];

void reset_map() {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++) map[i][j] = 0;
}

void reset_wmap() {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++) wmap[i][j] = 0;
}

int main() {
    ibs; cti;
    int w, h, wn, w_x, w_y;

    while (cin >> w >> h, w != 0 && h != 0) {
        cin >> wn;

        reset_map();
        reset_wmap();

        while (wn-- > 0) {
            cin >> w_x >> w_y;
            wmap[w_x][w_y] = 1;
        }

        map[0][0] = 1;

        for (int i = 0; i <= w; i++) {
            for (int j = 0; j <= h; j++) {
                if(i > 0 && !wmap[i-1][j])
                    map[i][j] += map[i-1][j];
                if(j > 0 && !wmap[i][j-1])
                    map[i][j] += map[i][j-1];
            }
        }

        if (map[w][h] > 1) {
            cout << "There are " << map[w][h] << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
        } else if (map[w][h] == 1) {
            cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
        } else {
            cout << "There is no path.\n";
        }
    }

    return 0;
}