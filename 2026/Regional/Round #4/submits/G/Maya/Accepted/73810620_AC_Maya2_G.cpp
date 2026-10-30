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

    vector<int> l(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> ol(n), oc(n);
    iota(ol.begin(), ol.end(), 0);
    iota(oc.begin(), oc.end(), 0);
    sort(ol.begin(), ol.end(), [&](auto& x, auto& y) {
        return l[x] < l[y];
    });
    sort(oc.rbegin(), oc.rend(), [&](auto& x, auto& y) {
        return c[x] < c[y];
    });


    vector g(n, vector<int>(n));
    int lc = 0;
    for (int i = 0; i < n; i++) {
        int ii = ol[i];
        while (l[ii]) {
            if (c[oc[lc]] >= l[ii]) {
                c[oc[lc]] -= l[ii];
                g[ii][oc[lc]] += l[ii];
                l[ii] = 0;
            } else {
                g[ii][oc[lc]] += c[oc[lc]];
                l[ii] -= c[oc[lc]];
                lc++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << " \n"[j == n - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ol[i] + 1 << " \n"[i == n - 1];
    }
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
