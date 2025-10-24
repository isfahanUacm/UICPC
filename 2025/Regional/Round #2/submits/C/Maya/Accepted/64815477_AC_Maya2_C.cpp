#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t a, b;
    cin >> a >> b;

    int TA = 32, TB = 32, TC = 32;
    if (a > numeric_limits<int>::max() || a < numeric_limits<int>::min()) {
        TA = 64;
    }
    if (b > numeric_limits<int>::max() || b < numeric_limits<int>::min()) {
        TB = 64;
    }

    __int128_t aa = a, bb = b;
    __int128_t c = aa * bb;
    if (c > numeric_limits<int>::max() || c < numeric_limits<int>::min()) {
        TC = 64;
        if (TA >= TB) {
            TA = 64;
        } else {
            TB = 64;
        }
    }
    if (c > numeric_limits<int64_t>::max() || c < numeric_limits<int64_t>::min()) {
        TC = 128;
        if (TA >= TB) {
            TA = 128;
        } else {
            TB = 128;
        }
    }

    cout << TA << '\n' << TB << '\n' << TC << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
