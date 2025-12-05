#include<bits/stdc++.h>
#include <iomanip>
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
    vector<array<Point, 2>> rects(n);
    for (int i=0; i<n; i++) {
        Point u, v; cin >> u[0] >> u[1] >> v[0] >> v[1];
        rects[i][0] = u;
        rects[i][1] = v;
    }
    ld ans = 0;
    if (b[1] >= a[1]) {
        cout << fixed << setprecision(8) << ans << nl;
        return;
    }
    ans = a[1]-b[1];
    for (int i=0; i<n; i++) {
        auto u = rects[i][0], v = rects[i][1];
        ans -= min(v[1], a[1])-max(u[1], b[1]);
    }
    cout << fixed << setprecision(8) << ans << nl;
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
