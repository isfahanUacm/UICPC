#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int inc = 0, dec = 0, eq = 0;
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

    int ans = eq * (n - 1) + dec * inc;
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
