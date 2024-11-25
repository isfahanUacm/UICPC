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
    ll ans = 0;
    array<int, 3> cnt = {n, n, n};
    while (cnt[0] >= 0 && cnt[1] >= 2) {
        cnt[0]--;
        cnt[1] -= 2;
        ans++;
    }
    vector<int> v;
    for (int i=0; i<3; i++) {
        for (int j=0; j<cnt[i]; j++) {
            if (i == 0) {
                v.pb(18);
            } else if (i == 1) {
                v.pb(21);
            } else {
                v.pb(25);
            }
        }
    }
    sort(v.begin(), v.end());
    int c = 0;
    for (int i=0; i<v.size(); i++) {
        if (c+v[i] <= 60) {
            c += v[i];
        } else {
            ans++;
            c = v[i];
        }
    }
    if (c) ans++;
    cout << ans << nl;
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