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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> r(n), g(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> g[i] >> d[i];
        d[i] = 1e4 - d[i];
    }

    int st = 1e4;
    for (int i = 0; i < n; i++) {
        st += a[i];
        int dis = st - d[i];
        int rem = dis % (r[i] + g[i]);
        if (rem >= g[i]) {
            st += (r[i] + g[i]) - rem;
        }
    }

    cout << st - 10000 << '\n';
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
