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
    int n, m; cin >> m >> n;
    vector a(n, vector<arr<char, 2>>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j][0] >> a[i][j][1];
        }
    }
    vector<char> ans(m, '?');
    for (int j=0; j<m; j++) {
        set<int> f;
        for (int i=0; i<n; i++) {
            if (a[i][j][1] == 'T') {
                ans[j] = a[i][j][0];
                break;
            } else {
                f.insert(a[i][j][0]);
            }
        }
        if (ans[j] == '?' && f.size() == 3) {
            for (char c = 'A'; c <= 'D'; c++) {
                if (f.count(c) == 0) {
                    ans[j] = c;
                    break;
                }
            }
        }
    }
    for (int i=0; i<m; i++) {
        cout << ans[i] << " \n"[i==m-1];
    }

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

