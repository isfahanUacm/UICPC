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

void solve(int tc) {
    int n; cin >> n;
    ld a, o; cin >> a >> o;
    ld Da, Do; cin >> Da >> Do;
    ld tot = max(0.0L, a-n*Da) + max(0.0L, o-n*Do);
    dbg(tot);
    ld alc = max(0.0L, a-n*Da);
    cout << fixed << setprecision(6) << 100.0*alc/tot << nl;
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

