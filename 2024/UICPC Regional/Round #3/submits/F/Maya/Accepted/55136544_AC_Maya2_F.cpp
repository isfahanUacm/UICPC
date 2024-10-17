#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;

    vector<double> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < k; i++) {
        vector<double> dp2(n + 1);
        for (int j = 0; j <= n; j++) {
            dp2[j] = dp[j] / 2;
            if (j - 1 >= 0) {
                dp2[j] += dp[j - 1] / 2;
            }
        }
        dp2[n - 1] += dp[n] / 2;
        dp = dp2;
    }

    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += i * dp[i];
    }
    cout << fixed << setprecision(6) << ans << '\n';
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
