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
        for (int j = i + 1; j < n; j++) {
            double mx = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (x[i] == x[j]) {
                    double d = fabs(y[j] - y[i]);
                    mx = max(mx, d);
                    continue;
                }
                double m = (double)abs(y[j] - y[i]) / abs(x[j] - x[i]);
                double c = -m * x[j] + y[j];
                double d = fabs(m * x[k] - y[k] + c) / sqrt(m * m + 1);
                dbg(x[j], x[i], m, d);
                mx = max(mx, d);
            }
            ans = min(ans, mx);
        }
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
