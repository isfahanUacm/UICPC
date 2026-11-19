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

const int M = 1006903069;
void solve([[ maybe_unused ]] uint32_t tc) {
    int n, ka, kb;
    cin >> n;
    cin >> ka;
    vector<vector<array<int, 2>>> row(n);
    for (int i=0; i<ka; i++) {
        int x, y, v; cin >> x >> y >> v; x--, y--;
        row[x].push_back({y, v});
    }
    map<array<int, 2>, int> mp;
    cin >> kb;
    for (int i=0; i<kb; i++) {
        int x, y, v; cin >> x >> y >> v; x--, y--;
        mp[{x, y}] = v;
    }
    ll ans = 0;
    for (int i=0; i<n; i++) {
        for (auto [j, v]: row[i]) {
            if (mp.contains({j, i})) {
                ans = (ans + (v%M * mp[{j, i}]%M)%M)%M;
            }
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