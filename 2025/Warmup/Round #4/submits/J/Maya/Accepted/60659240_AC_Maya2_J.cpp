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
    ll n, m, d; cin >> n >> m >> d;
    vector<ll> a(n), b(m);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int j=0; j<m; j++) {
        cin >> b[j];
    }
    ll t = -1, i=0, j=0, x=1, ta = a[n-1]-d, cnt = 0;
    while (1) {
        bool b1 = 0;
        if (x == 1) {
            for (; j<m; j++) {
                if (b[j] >= t+1 && b[j]+d < ta) {
                    t = b[j]+d;
                    x = 0;
                    b1 = 1;
                    cnt++;
                    break;
                }
            }
        } else {
            for (; i<n; i++) {
                if (a[i]-d >= t+1 && a[i] < ta) {
                    t = a[i];
                    x = 1;
                    b1 = 1;
                    cnt++;
                    break;
                }

            }
        }
        if (!b1) break;
    }
    cout << (x==0?'A':'B') << ' ' << cnt << nl;
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
