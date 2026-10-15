#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
//#define TIME
#define DEBUG
#ifdef LOCAL
#include "local.h"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

void solve([[ maybe_unused ]] int tc) {
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m, 1));
    for (int k=2; k<n+m; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i%(k-1) == 0 || j%(k-1) == 0) {
                    a[i][j] = lcm(a[i][j], k);
                    if (a[i][j] > (int)1e9) {
                        cout << "NO" << nl;
                        return;
                    }
                }
            }
        }
    }
    cout << "YES" << nl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    #ifdef TESTCASE
    cin >> t;
    #endif
    for (int i=1; i<=t; i++) {
        Solve(i);
    }
    return 0;
}

