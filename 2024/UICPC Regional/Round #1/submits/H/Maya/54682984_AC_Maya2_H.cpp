#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = a[0], hi, mx = 0;
    bool f = true;
    for (int i = 0; i < n - 1; i++) {
        if (f && a[i + 1] < a[i]) {
            f = false;
            hi = a[i];
        }
        else if (!f && a[i] < a[i + 1]) {
            f = true;
            mx = max(mx, min(hi - l, hi - a[i]));
            l = a[i];
        }
        else if (!f) {
            mx = max(mx, min(hi - l, hi - a[i]));
        }
    }
    if (!f) {
        mx = max(mx, min(hi - l, hi - a[n - 1]));
    }
    cout << mx << '\n';
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
