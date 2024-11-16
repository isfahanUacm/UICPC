#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m, L;
    cin >> n >> m >> L;

    vector<int> p(n), l(m);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }

    sort(p.begin(), p.end());
    sort(l.begin(), l.end());

    int mx = max(L - p[n - 1], p[0]);
    for (int i = 1; i < n; i++) {
        mx = max(mx, (p[i] - p[i - 1] + 1) / 2);
    }

    int ans = 2e9;
    for (int i = 0; i < m; i++) {
        if (l[i] >= mx) {
            ans = min(ans, l[i]);
        }
    }
    cout << (ans == 2e9 ? -1 : ans) << '\n';
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
