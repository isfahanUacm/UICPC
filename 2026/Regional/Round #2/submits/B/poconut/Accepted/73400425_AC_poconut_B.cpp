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
    string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    int l = 0, r = n-1, j = m-1;
    while (l < n && l < m && s[l] == t[l]) l++;
    while (r >= 0 && j >= 0 && s[r] == t[j]) {
        r--;
        j--;
    }
    if (s == t) {
        cout << 0 << nl;
    } else if ((n > m && (s.substr(0, m) == t || s.substr(n-m, m) == t)) ||  l > r) {
        cout << 1 << nl;
    } else {
        cout << 2 << nl;
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

