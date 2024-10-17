#include <bits/stdc++.h>
#ifndef LOCAL
#define LINE
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#else
#define LINE cerr << "----------" << nl;
#define fastio
#endif
using namespace std;
using ll = long long; using ld = long double;
#define nl '\n'
#define arr array
#define pb push_back

void solve() {
    int n; cin >> n;
    vector<int> h(n), r(n), t(n);
    int mx = 0;
    for (int i=0; i<n; i++) {
        cin >> h[i] >> r[i] >> t[i];
        mx = max(mx, h[i]);
    }
    for (int i=0; i<1825*mx; i++) {
        int cnt = 0;
        for (int j=0; j<n; j++) {
            int x = i%h[j];
            if (r[j] < t[j]) {
                if (r[j] < x && x < t[j]) {
                    cnt++;
                }
            } else {
                if (x<t[j] || (r[j]<x && x<h[j])) {
                    cnt++;
                }
            }
        }
        if (cnt == 0) {
            cout << i << nl;
            return;
        }
    }
    cout << "impossible" << nl;
}

int32_t main() {
    fastio
    int t = 1;
//cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}

