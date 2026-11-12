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

const int N = 1e6+5;
vector<int> spf(N);
vector<int> ps;
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
void solve([[ maybe_unused ]] uint32_t tc) {
    int n; cin >> n;
    cout << (int) (upper_bound(ps.begin(), ps.end(), n) - ps.begin()) << nl;
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


