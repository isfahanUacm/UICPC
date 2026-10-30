#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n;
    cin >> n;

    int64_t inc = 0, dec = 0, eq = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            inc++;
        } else if (x < y) {
            dec++;
        } else {
            eq++;
        }
    }

    int64_t ans = eq * (n - eq) + dec * inc + eq * (eq - 1) / 2;
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
