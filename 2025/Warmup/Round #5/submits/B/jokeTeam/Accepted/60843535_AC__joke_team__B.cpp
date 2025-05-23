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
    string a; cin >> a;
    int k; cin >> k;
    array<int, 26> w{};
    char mxc = 'a';
    int mx = -1;
    for (int i=0; i<26; i++) {
        cin >> w[i];
        if (w[i] > mx) {
            mxc = 'a'+i;
            mx = w[i];
        }
    }
    ll ans = 0;
    for (int i=0; i<k; i++) {
        a += mxc;
    }
    for (int i=0; i<(int)a.size(); i++) {
        ans += (i+1)*w[a[i]-'a'];
    }
    cout << ans << nl;
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

