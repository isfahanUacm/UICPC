#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t a, b;
    cin >> a >> b;

    __int128_t one = 1;
    __int128_t m1 = (one << 31) - 1;
    __int128_t m2 = (one << 63) - 1;

    __int128_t aa = a;
    __int128_t bb = b;

    __int128_t cc = aa * bb;

    
    int ta = 32, tb = 32, tc = 32;
    if (aa > m2) {
        ta = 128;
    } else if (aa > m1) {
        ta = 64;
    }
    if (bb > m2) {
        tb = 128;
    } else if (bb > m1) {
        tb = 64;
    }
    if (cc > m2) {
        tc = 128;
    } else if (cc > m1) {
        tc = 64;
    }

    if (ta > tb) {
        ta = max(ta, tc);
    } else {
        tb = max(tb, tc);
    }

    cout << ta << '\n' << tb << '\n' << tc << '\n';
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
