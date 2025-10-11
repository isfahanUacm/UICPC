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
    cout << "Case " << tc << ": ";
    int g = 6, e = 1;
    string a; cin >> a;
    int n = (int)a.size();
    int t1 = 0, t2 = 0;
    int i = 0;
    while (i<n && a[i] != ':') {
        t1 = 10*t1+(a[i]-'0');
        i++;
    }
    i++;
    while (i<n) {
        t2 = 10*t2+(a[i]-'0');
        i++;
    }
    if (e+t1 == g+t2) {
        e += 1;
        g += t2;
    }
    e += t1;
    g += t2;
    if (e > g) {
        cout << "YES" << nl;
    } else if (e < g) {
        cout << "NO" << nl;
    } else {
        cout << "PENALTIES" << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ghanophobia.in", "r", stdin);
    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}

