#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int h;
    cin >> h;

    int ans = 0, mn = 1e9;
    for (int i = 0; i < n; i++) {
        if (h % a[i] < mn) {
            mn = h % a[i];
            ans = a[i];
        }
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
