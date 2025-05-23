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
    array<int, 4> a{};
    for (int i=0; i<4; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto make = [&] (int x, int y, int z) {
        array<int, 3> t = {x, y, z};
        sort(t.begin(), t.end());
        return t[0]+t[1]-t[2];
    };
    dbg(a);
    int mx = -1;
    do {
        mx = max(mx, make(a[0], a[1], a[2]));
    } while (next_permutation(a.begin(), a.end()));

    if (mx < 0) {
        cout << "IMPOSSIBLE" << nl;
    } else if (mx == 0) {
        cout << "SEGMENT" << nl;
    } else {
        cout << "TRIANGLE" << nl;
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

