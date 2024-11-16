#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

void solve() {
    int n, m; cin >> n >> m;
    n += 2;
    m += 2;
    vector a(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    vector num(n, vector<int>(m));
    vector ans(n, vector<int>(m, -1));
    vector vis(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            num[i][j] = min(min(i, n-1-i), min(j, m-1-j));
            if (num[i][j] == 0) {
                ans[i][j] = 0;
            }
        }
    }
    auto ok = [&] (int i, int j) {
        return i>=0 && i<n && j>=0 && j<m;
    };
    auto make = [&] (int x, int y) {
        int cnt = 0;
        array<int, 2> pos{};
        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                int xx = x+i, yy = y+j;
                if (ok(xx, yy)) {
                    if (ans[xx][yy] == -1) {
                        pos = {xx, yy};
                    } else {
                        cnt += ans[xx][yy];
                    }
                }
            }
        }
        if (a[x][y] > cnt) {
            ans[pos[0]][pos[1]] = 1;
        } else {
            ans[pos[0]][pos[1]] = 0;
        }
    };
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
    auto dfs = [&] (auto&& dfs, int x, int y, int nu) -> void {
        make(x, y);
        vis[x][y] = 1;
        for (int i=0; i<4; i++) {
            int xx = x+dx[i], yy = y+dy[i];
            if (ok(xx, yy) && !vis[xx][yy] && num[xx][yy] == nu) {
                dfs(dfs, xx, yy, nu);
            }
        }
    };

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!vis[i][j]) {
                dfs(dfs, i, j, num[i][j]);
            }
        }
    }
    /*
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << nl;
    }
    */
    auto check = [&] (int x, int y) -> bool {
        int cnt = 0;
        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                int xx = x+i, yy = y+j;
                if (ok(xx, yy)) {
                    cnt += ans[xx][yy];
                }
            }
        }
        return cnt == a[x][y];
    };
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!check(i, j)) {
                cout << "impossible" << nl;
                return;
            }
        }
    }
    for (int i=1; i<n-1; i++) {
        for (int j=1; j<m-1; j++) {
            if (ans[i][j]) {
                cout << 'X';
            } else {
                cout << '.';
            }
        }
        cout << nl;
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
