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
    int n, p; cin >> n >> p;
    vector<int> s(p), t(p), f(p);
    for (int i=0; i<n; i++) {
        vector<char> c(p);
        vector<int> a(p);
        for (int j=0; j<p; j++) {
            cin >> c[j] >> a[j];
            if (c[j] == '+') {
                s[j]++;
            }
            if (!(c[j] == '-' && a[j] == 0)) {
                t[j]++;
            }
            f[j] += a[j];
        }
    }
    for (int i=0; i<p; i++) {
        cout << s[i] << ' ' << t[i] << ' ' << f[i] << nl;
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

