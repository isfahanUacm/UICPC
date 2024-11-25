#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int last_x = -1, last_y = -1;
    for (int i = n; i >= 1; i--) {
        if (gcd(i, a) == 1) {
            last_x = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (gcd(i, b) == 1) {
            last_y = i;
            break;
        }
    }

    dbg(last_x, last_y);
    int64_t ans = last_x + last_y - 2;
    for (int i = 1; i <= last_x; i++) {
        ans += gcd(i, a);
    }
    for (int i = 1; i <= last_y; i++) {
        ans += gcd(i, b);
    }

    vector dp(n - last_x + 1, vector<int>(n - last_y + 1));
    for (int i = last_x; i <= n; i++) {
        for (int j = last_y; j <= n; j++) {
            int ii = i - last_x, jj = j - last_y;
            dp[ii][jj] = gcd(a, i) + gcd(b, j);
            int mn = 1e9;
            if (ii - 1 >= 0) {
                mn = min(mn, dp[ii - 1][jj]);
            }
            if (jj - 1 >= 0) {
                mn = min(mn, dp[ii][jj - 1]);
            }
            if (mn != 1e9) {
                dp[ii][jj] += mn;
            }
        }
    }
    dbg(ans, dp);
    ans += dp[n - last_x][n - last_y] - gcd(a, last_x) - gcd(b, last_y);
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