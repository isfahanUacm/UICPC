#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n, m, k;
    cin >> n >> m >> k;

    int64_t ans = n;
    if ((m - 1) * n <= k) {
        if (m % 2 == 0) {
            ans = (m * n) - k;
        } else {
            ans = n - 1;
        }
    } else if (n % 2 == 0 && k % 2) {
        ans--;
    } else if (n % 2 && k % 2 == 0) {
        ans--;
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
