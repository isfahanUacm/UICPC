#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

   double ans = 1e9;
    for (int i = 0; i < n; i++) {
        double mx = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (j == i || k == i) {
                    continue;
                }
                double m = (double)abs(y[j] - y[k]) / abs(x[j] - x[k]);
                double c = -m * x[j] + y[j];
                double d = fabs(m * x[i] - y[i] + c) / sqrt(m * m + 1);
                dbg(d);
                mx = max(mx, d);
            }
        }
        dbg(i, x[i], y[i], mx);
        ans = min(ans, mx);
    }

    cout << fixed << setprecision(6) << ans << '\n';
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
