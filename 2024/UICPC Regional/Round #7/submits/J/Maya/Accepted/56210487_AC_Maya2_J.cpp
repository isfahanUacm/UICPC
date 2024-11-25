#include<bits/stdc++.h>
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
    char t; int c;
    ll num = 0;
    for (int i=0; i<n; i++) {
        cin >> t >> c;
        if (t == 'P') {
            num += c;
        } else {
            if (c > num) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
            num -= min<ll>(c, num);
        }
    }
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