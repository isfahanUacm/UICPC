#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t r;
    cin >> r;

    auto check = [&](int64_t x, int64_t y) {
        int64_t dis = x * x + y * y;
        return dis > r * r;
    };

    int64_t mn = 1e18;
    int mn_x = -1, mn_y = -1;
    for (int64_t i = 0; i <= r; i++) {
        int64_t lo = 0, hi = r + 1;
        while (hi - lo > 1) {
            int64_t mid = lo + (hi - lo) / 2;
            if (check(i, mid)) {
                hi = mid; 
            }
            else {
                lo = mid;
            }
        }
        if (i * i + hi * hi < mn) {
            mn = i * i + hi * hi;
            mn_x = i, mn_y = hi;
        }
    }
    cout << mn_x << ' ' << mn_y << '\n';
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
