#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<array<int64_t, 2>> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = a[i] + max(dp[i][0], dp[i][1]);
        dp[i + 1][1] = 2 * a[i] + dp[i][0];
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';

    int v = 0;
    string s = "";
    for (int i = n; i > 0; i--) {
        if (v == 1) {
            v = 0;
        }
        else if (dp[i][0] > dp[i][1]) {
            v = 0;
        }
        else {
            v = 1;
        }
        s += v == 0 ? "O" : "M";
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
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
