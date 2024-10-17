#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] ? 1.0 / a[i] : 2.0;
    }
    cout << fixed << setprecision(8) << ans << '\n';
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
