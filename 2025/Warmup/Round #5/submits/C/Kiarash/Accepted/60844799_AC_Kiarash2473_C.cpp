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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int64_t> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i - 1];
    }

    int64_t ans = 0;
    for (int k = 1; k <= n; k++) {
        if (n % k) {
            continue;
        }
        int64_t mn = 1e18, mx = 0;
        for (int i = 0; i + k <= n; i += k) {
            int64_t v = p[i + k] - p[i];        
            mn = min(mn, v);
            mx = max(mx, v);
        }
        ans = max(ans, mx - mn);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
