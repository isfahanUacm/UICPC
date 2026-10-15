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
    int n; cin >> n;
    vector<int> cnt(n);
    for (int i=0; i<n; i++) {
        int t; cin >> t, t--;
        cnt[t]++;
    }
    for (int i=0; i<n; i++) {
        if (cnt[i] > 1) {
            cout << "Yes" << nl;
            return;
        }
    }
    cout << (n % 2 == 0 ? "Yes" : "No") << nl;
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

