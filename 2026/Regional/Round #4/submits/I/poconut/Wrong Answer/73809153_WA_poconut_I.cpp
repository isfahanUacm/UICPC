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
    ll n, m, k; cin >> n >> m >> k;
    ll lo = 0, hi = n+1;
    while (hi - lo > 1) {
        //md k-md
        // x <= (md-1)*m / 2
        // x <= (k-md) / 2
        // (x+md-1)/md <
        
        // (k-md - x*2) <= (n-md)*m
        // x >= (k-md) - (n - md)*m / 2 && x <= (k-md) / 2
        ll md = lo + (hi - lo) / 2;
        ll x = (k - md - (n - md) * m + 1) / 2;
        if (x <= min((md-1)*m/2, (k - md) / 2) && (x+md-1)/md*2 + 1 <= m) {
            lo = md;
        } else {
            hi = md;
        }
    }
    cout << lo << nl;
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


