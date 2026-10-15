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
    vector<int> a(n), w(n);
    multiset<int> s;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i=0; i<n; i++) {
        cin >> w[i];
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
            return w[i] > w[j];
            });

    ll ans = 0;
    for (int i: ord) {
        auto it = s.upper_bound(i+1);
        if (it != s.begin()) {
            it--;
            if (*it <= i+1) {
                ans += w[i];
                s.erase(s.find(*it));
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

