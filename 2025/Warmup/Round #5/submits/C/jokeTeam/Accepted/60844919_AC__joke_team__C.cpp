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

const int N = 150005;
const ll INF = 1e18+5;

void solve(int tc) {
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> ps(n+1);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        ps[i+1] = ps[i]+a[i];
    }
    auto make = [&] (int i) {
        ll mn = INF, mx = -1;
        for (int j=i; j<=n; j+=i) {
            mn = min(mn, ps[j]-ps[j-i]);
            mx = max(mx, ps[j]-ps[j-i]);
        }
        return mx-mn;
    };
    ll ans = 0;
    for (int i=1; i*i<=n; i++) {
        if (n%i == 0) {
            ans = max(ans, make(i));
            ans = max(ans, make(n/i));
        }
    }
    cout << ans << nl;
    /*
    auto calc = [&] (int n) {
        int c = 0;
        for (int i=1; i*i<=n; i++) {
            if (n%i==0) {
                c += 2;
                if (i*i == n) {
                    c--;
                }
            }
        }
        return c;
    };
    int mx= 0;
    for (int i=1; i<N; i++) {
        mx = max(mx, calc(i));
    }
    cout << mx << nl;
    */
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}

