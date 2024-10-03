#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;

    int x0, y0, xt, yt;
    cin >> x0 >> y0 >> xt >> yt;

    vector<int> x(n), y(n);
    const int N = 2000;
    vector g(4000, vector<char>(4000));
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        g[x[i] + N][y[i] + N] = 1;
    }

    auto is_exist = [&](int xx, int yy) {
        return g[xx + N][yy + N];
    };

    auto exist = [&](auto &&self, int xc, int yc, int dx, int dy, int nxx, int nyy) -> bool {
        if (xc + dx == nxx && yc + dy == nyy) {
            return true;
        }
        if (is_exist(xc + dx, yc + dy)) {
            return self(self, xc + dx, yc + dy, dx, dy, nxx, nyy);
        }
        return false;
    };

    vector<bool> vis(n);
    auto move = [&](int xc, int yc, int dx, int dy) {
        for (int i = 0; i < n; i++) {
            if (xc == x[i] && yc == y[i]) {
                g[x[i] + N][y[i] + N] = 0;
                x[i] = xc + dx;
                y[i] = yc + dy;
                if (x[i] == xt && y[i] == yt) {
                    x[i] = 2000, y[i] = 2000;
                    vis[i] = true;
                }
                else {
                    g[x[i] + N][y[i] + N] = 1;
                }
                return;
            }
        }
    };

    auto gogo = [&](auto &&self, int xc, int yc, int dx, int dy) -> void {
        if (is_exist(xc + dx, yc + dy)) {
            self(self, xc + dx, yc + dy, dx, dy);
        }
        move(xc, yc, dx, dy);
    };

    auto go = [&](int xx, int yy, int nxx, int nyy) {
        while (x0 != xx || y0 != yy) {
            dbg(x0, xx, y0, yy, x, y);
            bool f1 = false, f2 = false;
            if (x0 < xx) {
                if (!exist(exist, x0, y0, 1, 0, nxx, nyy)) {
                    gogo(gogo, x0, y0, 1, 0);
                    x0++;
                    cout << "right\n";
                }
                else {
                    f1 = true;
                }
            }
            if (x0 > xx) {
                if (!exist(exist, x0, y0, -1, 0, nxx, nyy)) {
                    gogo(gogo, x0, y0, -1, 0);
                    x0--;
                    cout << "left\n";
                }
                else {
                    f1 = true;
                }
            }
            dbg(f1, y0, yy);
            if (f1 && y0 == yy) {
                gogo(gogo, x0, y0, 0, 1);
                y0++;
                cout << "up\n";
                continue;
            }
            l1:
            f2 = false;
            if (y0 < yy) {
                if (!exist(exist, x0, y0, 0, 1, nxx, nyy)) {
                    gogo(gogo, x0, y0, 0, 1);
                    y0++;
                    cout << "up\n";
                }
                else {
                    f2 = true;
                }
            }
            if (y0 > yy) {
                if (!exist(exist, x0, y0, 0, -1, nxx, nyy)) {
                    gogo(gogo, x0, y0, 0, -1);
                    y0--;
                    cout << "down\n";
                }
                else {
                    f2 = true;
                }
            }
            if (f1 && f2 && x0 == xx) {
                gogo(gogo, x0, y0, 1, 0);
                x0++;
                cout << "right\n";
                goto l1;
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (xt > x[i]) {
                go(x[i] - 1, y[i], x[i], y[i]);
                go(xt - 1, y[i], 1000, 1000);
            }
            else if (xt < x[i]) {
                go(x[i] + 1, y[i], x[i], y[i]);
                go(xt + 1, y[i], 1000, 1000);
            }
            if (!vis[i] && yt > y[i]) {
                go(x[i], y[i] - 1, x[i], y[i]);
                go(x[i], yt - 1, 1000, 1000);
            }
            else if (!vis[i] && yt < y[i]) {
                go(x[i], y[i] + 1, x[i], y[i]);
                go(x[i], yt + 1, 1000, 1000);
            }
            vis[i] = true;
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
