#include <bits/stdc++.h>
using namespace std;

// جهت‌ها: 0 = راست, 1 = پایین, 2 = چپ, 3 = بالا
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main() {
    int r, c;
    cin >> r >> c;

    int si, sj, ei, ej;
    cin >> si >> sj;
    cin >> ei >> ej;

    vector<string> maze(r);
    for (int i = 0; i < r; i++) cin >> maze[i];


    si--; sj--; ei--; ej--;


    int i = si, j = sj, dir = 0;

    set<tuple<int, int, int>> visited;

    while (true) {

        if (i == ei && j == ej) {
            cout << 1;
            return 0;
        }


        if (visited.count({i, j, dir})) {
            cout << 0;
            return 0;
        }
        visited.insert({i, j, dir});


        int leftDir = (dir + 3) % 4;
        int ni = i + di[leftDir];
        int nj = j + dj[leftDir];


        if (ni >= 0 && ni < r && nj >= 0 && nj < c && maze[ni][nj] == '0') {
            dir = leftDir;
            i = ni;
            j = nj;
        }

        else {
            int fi = i + di[dir];
            int fj = j + dj[dir];
            if (fi >= 0 && fi < r && fj >= 0 && fj < c && maze[fi][fj] == '0') {
                i = fi;
                j = fj;
            }

            else {
                dir = (dir + 1) % 4;
            }
        }
    }
}
