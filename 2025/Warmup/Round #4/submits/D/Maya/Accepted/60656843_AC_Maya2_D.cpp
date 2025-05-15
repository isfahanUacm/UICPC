#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define TC solve
#endif
#define nl '\n'

void solve(int tc) {
    int n; cin >> n;
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (a == c) {
        cout << d-b << nl;
    } else {
        ll ans = (c-a-1)*(n+1) + (n-b+1) + d;
        cout << ans << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}
