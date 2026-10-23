#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
#ifdef LOCAL
#include "local.hpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

void solve([[ maybe_unused ]] uint32_t tc) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = n-1;
    for (int i=0, c=0, l=-1; i<n; i++) {
        if (l == -1) {
            l = i;
        }
        c++;
        if (i+1 == n || a[i+1] - a[i] > 1) {
            ans = min(ans, n-c);
            l = -1;
            c = 0;
        }
    }
    cout << ans << nl;
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


