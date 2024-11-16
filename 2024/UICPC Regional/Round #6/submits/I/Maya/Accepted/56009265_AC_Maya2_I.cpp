#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = 1e9, mx = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            ans = min(ans, max(mx, b[i] - a[i]));
        }
        ans = min(ans, max(mx, b[i] - a[i] + 1));
        mx = max(mx, b[i] - a[i]);
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
