#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            return;
        }

        vector<int64_t> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        int64_t ans = m - 2 * (m / 7) - (m % 7 == 6);
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] <= m && a[i] % 7 != 6 && a[i] % 7 != 0) {
                ans--;
            }
        }
        cout << ans << '\n';
    }

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
