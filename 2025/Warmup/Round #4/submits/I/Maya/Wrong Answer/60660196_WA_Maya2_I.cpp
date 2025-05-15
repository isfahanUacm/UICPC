#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int Sp, Sm, Dp, Dm, Tp, Tm, E;
    cin >> Sp >> Sm >> Dp >> Dm >> Tp >> Tm >> E;

    int Rp = max(0, E - Sp), Rm = max(0, E - Sm);
    int Day_p = Rp / Dp, Day_m = Rm / Dm;
    dbg(Rp, Rm, Day_p, Day_m);

    auto ok = [&](int x, int R, int D) {
        R -= x * D;
        int mx = max(Day_m, Day_p) - x;
        R -= (mx / 2) * D;
        return R <= 0;
    };

    int64_t minutes = 0;
    if (Day_p <= Day_m) {
        minutes = (int64_t)4 * Tm * Day_m; 
        dbg(minutes);
        int lo = -1, hi = Day_m;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid, Rp, Dp)) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        dbg(hi);
        minutes += (int64_t)4 * Tp * hi;
        minutes += (int64_t)Tp * (Day_m - hi);
    }
    else {
        minutes = (int64_t)4 * Tp * Day_p; 
        int lo = -1, hi = Day_p;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid, Rm, Dm)) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        minutes += (int64_t)4 * Tm * hi;
        minutes += (int64_t)Tm * (Day_p - hi);
    }

    cout << max(Day_p, Day_m) << '\n';
    cout << minutes << '\n';
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
