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

    vector<array<int, 4>> a(n);
    //map<int, int> mp1, mp2;
    vector<int> mp1(2*n+5), mp2(2*n+5);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
            if (!mp1[a[i][j]]) {
                mp1[a[i][j]] = i + 1;
            }
            else {
                mp2[a[i][j]] = i + 1;
            }
        }
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == a[i][(j + 1) % 4]) {
                cnt++;
                break;
            }
        }
    }

    if (cnt > 4) {
        cout << "impossible\n";
        return;
    }

    auto rotate_left = [](array<int, 4> &x) {
        x = {x[1], x[2], x[3], x[0]};
    };

    int num = 0;
    auto work = [&](int x) {
        vector<bool> vis(n);
        num++;
        vector<vector<int>> ans;
        while (true) {
            vector<int> v;
            if (ans.size()) {
                if (a[ans.back()[0]][2] == 0) {
                    break;
                }
                int y1 = mp1[a[ans.back()[0]][2]], y2 = mp2[a[ans.back()[0]][2]];
                y1--, y2--;
                x = y1 == ans.back()[0] ? y2 : y1;
                while (a[x][0] != a[ans.back()[0]][2]) {
                    rotate_left(a[x]);
                }
            }
            if (vis[x]) {
                return false;
            }
            vis[x] = true;
            v.push_back(x);
            while (true) {
                if (a[v.back()][3] == 0) {
                    break;
                }
                int y1 = mp1[a[v.back()][3]], y2 = mp2[a[v.back()][3]];
                y1--, y2--;
                int y = y1 == x ? y2 : y1;
                while (a[y][1] != a[v.back()][3]) {
                    rotate_left(a[y]);
                }
                v.push_back(y);
                x = y;
                if (vis[x]) {
                    return false;
                }
                vis[x] = true;
            }
            ans.push_back(v);
        }

        int nn = ans.size(), mm = ans[0].size();
        if (nn == 0 || mm == 0 || nn * mm != n) {
            return false;
        }
        for (int i = 0; i < nn; i++) {
            if (ans[i].size() != mm) {
                return false;
            }
        }
        for (int i = 0; i < nn; i++) {
            if (a[ans[i][0]][1] != 0 || a[ans[i][mm - 1]][3] != 0) {
                return false;
            }
        }
        for (int j = 0; j < mm; j++) {
            if (a[ans[0][j]][0] != 0 || a[ans[nn - 1][j]][2] != 0) {
                return false;
            }
        }
        for (int i = 1; i < nn; i++) {
            for (int j = 0; j < mm; j++) {
                if (a[ans[i][j]][0] != a[ans[i - 1][j]][2] || a[ans[i][j]][0] == 0) {
                    return false;
                }
            }
        }

        cout << nn << ' ' << mm << '\n';
        for (int i = 0; i < nn; i++) {
            for (int j = 0; j < mm; j++) {
                cout << ans[i][j] + 1 << " \n"[j == mm - 1];
            }
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][0] == a[i][1] && a[i][0] == 0) {
                if (work(i)) {
                    return;
                }
            }
            rotate_left(a[i]);
        }
    }
    cout << "impossible\n";
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
