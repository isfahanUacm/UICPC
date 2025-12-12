#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int64_t> dp(n);
    int64_t mx = 0;
    for (int i = 0; i < n; i++) {
        if (i - k >= 0) {
            mx = max<int64_t>(mx, dp[i - k]);
        }
        dp[i] = max(dp[i], mx + a[i]);
    }

    int64_t ans = *max_element(dp.begin(), dp.end());
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
