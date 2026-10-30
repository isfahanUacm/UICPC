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
    int l=0, r = n-1;
    while (l < r && a[l] == 1) l++;
    while (l < r && a[r] == 1) r--;
    if ((int)count(a.begin(), a.end(), a[0]) == n) {
        if (a[0] == 1) {
            cout << 0 << nl;
        } else if ((int)count(a.begin(), a.end(), a[l]) == r - l + 1) {
            cout << 1 << nl;
        }
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


