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
    int n, q; cin >> n >> q;
    vector<int> id(n);
    vector<int> even(n);
    vector<int> v;
    int c = 0;
    for (int i=0; i<2*n-1; i++) {
        if (i&1) {
            char x; cin >> x;
            if (x != '*') {
                c++;
                dbg(i, c);
            }
        } else {
            int t; cin >> t;
            v.push_back(t);
            if (t%2 == 0) {
                even[c]++;
            }
            dbg(i/2, c);
            id[i/2] = c;
        }
    }
    c++;
    dbg(id, even, v, c);
    int ans = 0;
    for (int i=0; i<c; i++) {
        if (even[i]==0) ans++;
    }
    cout << (ans&1?"odd":"even") << nl;
    while (q--) {
        int a, b; cin >> a >> b;
        a--;
        ans -= even[id[a]]!=0;
        even[id[a]] -= (v[a]%2)==0;
        even[id[a]] += b%2==0;
        v[a] = b;
        ans += even[id[a]]!=0;
        cout << (ans&1?"odd":"even") << nl;
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

