#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n, t;
    cin >> n >> t;

    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto ok = [&](int64_t x) {
        int64_t sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (a[i] + x - 1) / x;
        }
        return sum <= t;
    };

    int64_t lo = 0, hi = 1e12;
    while (hi  - lo > 1) {
        int64_t mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << '\n';
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
