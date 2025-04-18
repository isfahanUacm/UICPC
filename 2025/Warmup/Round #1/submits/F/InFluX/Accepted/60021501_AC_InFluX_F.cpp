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
    vector<int> a(n), r(n), g(n), d(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> r[i] >> g[i] >> d[i];
    }
    int time = 0;
    for (int i=0; i<n; i++) {
        time += a[i];
        // time <= -d[i]+t*(r[i]+g[i]) -> (time+d[i])/(r[i]+g[i]) <= t
        int t = (time+d[i]+r[i]+g[i]-1)/(r[i]+g[i]);
        if (-d[i]+(t-1)*(r[i]+g[i])+g[i] > time) {
            continue;
        } else {
            time += -d[i]+t*(r[i]+g[i])-time;
        }
    }
    cout << time << nl;
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

