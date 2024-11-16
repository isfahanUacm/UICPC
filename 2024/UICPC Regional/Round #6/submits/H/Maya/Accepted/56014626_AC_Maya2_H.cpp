#include <bits/stdc++.h>
using namespace std;

template <typename T>
T power(T a, int64_t b) {
    assert(b >= 0);
    T res{1};
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int64_t m;
    cin >> m;

    for (int i = 3; i <= 60; i++) {
        __int128_t res = 0;
        int64_t j = 1;
        for (; res < m; j++) {
            res += power<__int128_t>(j, i - 1);
        }
        if (res == m) {
            cout << i << ' ' << j - 1 << '\n';
            return;
        }
    }
    cout << "impossible\n";
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
