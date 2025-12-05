#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int r, c;
    cin >> r >> c;

    vector<string> g(r);
    int xs = -1, ys = -1;
    for (int i = 0; i < r; i++) {
        cin >> g[i];
        for (int j = 0; j < c; j++) {
            if (g[i][j] == 'S') {
                xs = i, ys = j;
                g[i][j] = '.';
            }
        }
    }

    string s;
    cin >> s;

    int n = s.size();

    vector<int> dx(140), dy(140);
    dx['S'] = 1;
    dx['N'] = -1;
    dy['E'] = 1;
    dy['W'] = -1;
    auto check = [&](int x, int y) -> bool {
        return x >= 0 && x < r && y >= 0 && y < c;
    };

    vector dp(24, vector<int>(n + 1, 1e9));
    for (int i = 0; i < 24; i++) {
        dp[i][n] = 0;
    }

    string move = "NESW";
    sort(move.begin(), move.end());
    vector<string> moves;
    vector<int> xx(n + 1), yy(n + 1);
    xx[0] = xs, yy[0] = ys;
    for (int i = 1; i < n; i++) {
        xx[i] = xx[i - 1] + dx[s[i - 1]];
        yy[i] = yy[i - 1] + dy[s[i - 1]];
    }
    do {
        moves.push_back(move);
    } while (next_permutation(move.begin(), move.end()));
    dbg(moves);

    auto ok = [&](int i, int ind) {
        move = moves[ind];
        for (int j = 0; j < 4; j++) {
            if (s[i] == move[j]) {
                return true;
            }
            int x_tmp = xx[i] + dx[move[j]], y_tmp = yy[i] + dy[move[j]]; 
            if (check(x_tmp, y_tmp) && g[x_tmp][y_tmp] != '#') {
                return false; 
            }
        }
        return true;
    };

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 24; j++) {
            for (int k = 0; k < 24; k++) {
                if (ok(i, k)) {
                    if (j == k) {
                        dp[j][i] = min(dp[j][i], dp[k][i + 1]);
                    } else {
                        dp[j][i] = min(dp[j][i], dp[k][i + 1] + 1);
                    }
                }
            }
        }
    }
    dbg(dp);

    int ans = 1e9;
    for (int i = 0; i < 24; i++) {
        ans = min(ans, dp[i][0]);
    }

    cout << ans << '\n';
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
