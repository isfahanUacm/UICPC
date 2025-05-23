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

    vector dp(n + 1, vector<double>(n + 1));
    for (int i = 0; i <= n; i++) {
        dp[0][i] = i;
        dp[i][0] = -i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = ((double)(max(0, i - j)) / i * dp[i - 1][j - 1]) + ((double)(min(i, j)) / i * dp[i - 1][j]);
        }
    }
    dbg(dp);
    cout << fixed << setprecision(6);
    for (int i = 0; i <= n; i++) {
        cout << dp[n][i] << " \n"[i == n];
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
