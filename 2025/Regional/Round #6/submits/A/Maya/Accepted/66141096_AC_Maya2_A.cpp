#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
//#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

void solve([[ maybe_unused ]] int tc) {
    int n; cin >> n;
    using Point = array<int, 2>;
    Point a, b; cin >> a[0] >> a[1] >> b[0] >> b[1];
    const int N = 1e6+5;
    vector<int> ps(2*N+1);
    for (int i=0; i<n; i++) {
        Point u, v; cin >> u[0] >> u[1] >> v[0] >> v[1];
        ps[N+v[1]]--;
        ps[N+u[1]]++;
    }
    for (int i=1; i<(int)ps.size(); i++) {
        ps[i] += ps[i-1];
    }
    int ans = 0;
    for (int i=N+b[1]; i<N+a[1]; i++) {
        if (ps[i]==0) {
            ans++;
        }
    }
    cout << fixed << setprecision(8) << (ld)ans << nl;
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
