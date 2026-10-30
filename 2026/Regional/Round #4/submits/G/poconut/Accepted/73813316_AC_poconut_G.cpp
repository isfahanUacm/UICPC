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
    vector<int> c(n), l(n);
    for (int i=0; i<n; i++) {
        cin >> l[i];
    }
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
            return l[i] < l[j];
            });

    vector<int> ordc(n);
    iota(ordc.begin(), ordc.end(), 0);
    sort(ordc.begin(), ordc.end(), [&] (int i, int j) {
            return c[i] > c[j];
            });
    vector<vector<int>> ans(n, vector<int>(n));
    int j=0;
    for (int i: ord) {
        while (l[i]>0 && j < n && c[ordc[j]] > 0) {
            int t = min(l[i], c[ordc[j]]);
            c[ordc[j]] -= t;
            l[i] -= t;
            ans[i][ordc[j]] += t;
            if (c[ordc[j]] == 0) {
                j++;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int k=0; k<n; k++) {
            cout << ans[i][k] << ' ';
        }
        cout << nl;
    }
    for (int i=0; i<n; i++) {
        cout << ord[i]+1 << ' ';
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


