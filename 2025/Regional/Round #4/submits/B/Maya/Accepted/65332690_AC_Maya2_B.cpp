#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int r, c, n;
    cin >> r >> c >> n;

    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
    vector mn1(r, vector<int>(c, -1));
    vector mn2(r, vector<int>(c, -1));
    vector mp(r, vector<int>(c, -1));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        pq.push({0, i, x, y});
        mn1[x][y] = i;
        mp[x][y] = i;
    }

    constexpr int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
    constexpr int dy[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
    const string move = "UDLR";
    auto check = [&](int x, int y) -> bool {
        return x >= 0 && x < r && y >= 0 && y < c;
    };
    dbg(mn1);

    while (!pq.empty()) {
        auto [dis, ind, x, y] = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (check(xx, yy) && mn1[xx][yy] == -1) {
                mn1[xx][yy] = ind;
                pq.push({dis + 1, ind, xx, yy});
            } else if (check(xx, yy) && mn2[xx][yy] == -1 && mn1[xx][yy] != ind) {
                mn2[xx][yy] = ind;
                pq.push({dis + 1, ind, xx, yy});
            }
        }
    }



    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mn1[i][j] + 1 << " \n"[j == c - 1];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mn2[i][j] + 1 << " \n"[j == c - 1];
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
