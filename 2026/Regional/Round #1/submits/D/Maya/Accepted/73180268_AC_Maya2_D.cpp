#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
//#define TESTCASE
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
    int n, s; cin >> n >> s; s--;
    char c; cin >> c;
    if (c == 'L') {
        cout << s/2 + 1 << ' ' << s/2 + 1 << ' ' << n-s-1 << nl;
    } else {
        cout << s << ' ' << (n-s+1)/2 << ' ' << (n-s+1)/2 << nl;
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

