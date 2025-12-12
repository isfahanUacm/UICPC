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
    string a; cin >> a;
    int n = (int)a.size();
    auto valid = [&] (string t) {
        return (t != "" && (int)t.size() <= 2 && t[0] != '0');
    };
    int cnt = 0;
    string res1, res2;
    for (int i=1; i<n; i++) {
        string s1 = a.substr(0, i), s2 = a.substr(i, n-i);
        dbg(s1, s2);
        if (valid(s1) && valid(s2)) {
            res1 = s1, res2 = s2;
            cnt++;
        }
    }
    if (cnt == 1) {
        cout << res1 << ' ' << res2 << nl;
    } else {
        cout << -1 << nl;
    }
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
