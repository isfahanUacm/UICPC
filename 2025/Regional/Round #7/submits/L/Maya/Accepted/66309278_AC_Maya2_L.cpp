#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int64_t d, y;
    cin >> d >> y;

    int64_t sum = 0;
    int f = 1;
    for (int64_t i = 1; sum < d; i *= 2) {
        sum += i / 4;
        if (sum >= d) {
            cout << "Nao\n";
            return;
        }
        if (i <= 2) {
            sum += i;
        }
        sum += 3 * (i / 4);
        if (sum >= d) {
            cout << "Sim\n";
            if (f) {
                cout << y - (i - (sum - d)) << '\n';
            } else {
                cout << y + (i - (sum - d)) << '\n';
            }
            return;
        }
        sum += i;
        if (sum >= d) {
            cout << "Nao\n";
            return;
        }
        f ^= 1;
    }
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
