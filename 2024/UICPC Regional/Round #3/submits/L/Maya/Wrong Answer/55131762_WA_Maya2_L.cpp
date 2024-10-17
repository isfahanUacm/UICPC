#include <bits/stdc++.h>
using namespace std;

void solve() {
    int tx, ty;
    cin >> tx >> ty;

    int n;
    cin >> n;

    vector<int> x(n), y(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }

    map<array<int, 2>, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int p =  y[i] - ty, q = x[i] - tx;
        int g = gcd(p, q);
        p /= g;
        q /= g;
        mp[{p, q}].push_back(i);
    }

    auto dis = [&](int i) {
        int xx = x[i], yy = y[i];
        int64_t d = (xx - tx) * (xx - tx) + (yy - ty) * (yy - ty);
        return d;
    };

    auto lis = [&](vector<int> &v) {
        const int INF = 1e9;
        int n = v.size();

        vector<int> dp(n + 1, INF);
        dp[0] = -INF;
        for (int i = 0; i < n; i++) {
            int x = upper_bound(dp.begin(), dp.end(), h[i]) - dp.begin();
            if (h[i] > dp[x - 1]) {
                dp[x] = h[i];
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i] != INF) {
                res = i;
            }
        }
        return res;
    };

    int ans = 0;
    for (auto [x, v] : mp) {
        sort(v.begin(), v.end(), [&](int i, int j) {
            return dis(i) < dis(j);
        });
        ans += lis(v);
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
