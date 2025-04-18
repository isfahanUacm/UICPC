#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, M, k;
    cin >> n >> M >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 1, prv = a[0], sz = 1;
    for (int i = 1; i < n; i++) {
        if (sz + 1 <= k && abs(a[i] - prv) <= M) {
            sz++;
            prv = min(prv, a[i]);
        }
        else {
            sz = 1;
            prv = a[i];
            ans++;
        }
    }
    if (sz != 1) {
        ans++;
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
