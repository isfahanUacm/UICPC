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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[n-i-1];
    }
    int t;
    while (q--) {
        cin >> t;
        vector<int> tmp;
        for (int i=0; i<t; i++) {
            if (i&1) {
                tmp.pb(a.back());
            }
            a.pop_back();
        }
        for (int x: tmp) {
            a.pb(x);
        }
    }
    reverse(a.begin(), a.end());
    for (int x: a) {
        cout << x << ' ';
    }
    cout << nl;

}

int32_t main() {
    fastio
    int t = 1;
cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}

