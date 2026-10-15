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

const int N = 1e6+5;
vector<int> spf(N), ps;
void sieve() {
    for (int i=2; i<N; i++) {
        if (!spf[i]) {
            ps.push_back(i);
            for (int j=i; j<N; j+=i) {
                spf[j] = i;
            }
        }
    }
}
void solve([[ maybe_unused ]] int tc) {
    int m; cin >> m;
    vector<int> mx(m);
    for (int i=2; i<=m; i++) {
        int t = i;
        while (t > 1) {
            int p = spf[t], c = 0;
            while (t%p == 0) {
                t /= p;
                c++;
            }
            mx[p] = max(mx[p], c);
        }
    }
    ll ans = 1;
    for (int i=0; i<m; i++) {
        if (!mx[i]) continue;
        ll lo = 0, hi = m;
        while (hi - lo > 1) {
            ll md = lo + (hi - lo) / 2;
            if (md * (md + 1) / 2 < mx[i]) {
                lo = md;
            } else {
                hi = md;
            }
        }
        ans += hi;
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    sieve();
    
    #ifdef TESTCASE
    cin >> t;
    #endif
    for (int i=1; i<=t; i++) {
        Solve(i);
    }
    return 0;
}

