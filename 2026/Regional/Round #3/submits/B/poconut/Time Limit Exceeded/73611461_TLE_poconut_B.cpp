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

const int N = 2e6+5;
vector<int> spf(N);
void sieve() {
    for (int i=2; i<N; i++) {
        if (!spf[i]) {
            for (int j=i; j<N; j+=i) {
                spf[j] = i;
            }
        }
    }
}
void solve([[ maybe_unused ]] uint32_t tc) {
    int n; cin >> n;
    // b - a | ab
    // k | b * (b - k)
    // kt = b * (b - k)
    // 0 == ((b%k)^2)%k
    // k | b^2
    ll ans = 0;
    /*
    for (int i=2; i<=n; i++) {
        ll t = i*i;
        ll res = 1;
        while (t > 1) {
            int p = spf[t];
            int c = 0;
            while (t % p == 0) {
                t /= p;
                c++;
            }
            dbg(i, t, p, c);
            res *= (c+1);
        }
        ans += res;

    }
    */
    /*
    */
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if ((i * i) % j == 0) {
                ans++;
            }
        }
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


