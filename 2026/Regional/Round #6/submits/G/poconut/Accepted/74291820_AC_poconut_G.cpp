#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
//#define TESTCASE
#ifdef LOCAL
#include "local.hpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

void solve([[ maybe_unused ]] uint32_t tc) {
    int n, b; cin >> n >> b;
    vector<int> a(n-1);
    for (int i=0; i<n-1; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    ll ans = b+a[0];
    if (ans >= 0) {
        for (int i=1; i<n-1; i++) {
            if (a[i] >= 0) {
                ans += a[i];
            }
        }
        cout << ans << nl;
    } else {
        cout << -1 << nl;
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