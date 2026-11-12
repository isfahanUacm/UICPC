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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    for (int i=0, j=0; i<m; i++) {
        while (j<n && a[j] < i+1) {
            sum -= a[j];
            j++;
        }
        cout << sum << ' ';
    }
    cout << nl;
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


