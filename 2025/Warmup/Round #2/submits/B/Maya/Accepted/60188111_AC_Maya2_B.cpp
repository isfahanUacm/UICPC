#include <bits/stdc++.h>
using namespace std;

void solve() {
    int xs, ys, xe, ye, xp, yp;
    cin >> xs >> ys >> xe >> ye >> xp >> yp;

    int mn = -1e9, mx = 1e9;
    if (yp > max(ys, ye)) {
        cout << 2 << '\n';
        cout << xs << ' ' << mn << '\n';
        cout << xe << ' ' << mn << '\n';
    }
    else if (yp < min(ys, ye)) {
        cout << 2 << '\n';
        cout << xs << ' ' << mx << '\n';
        cout << xe << ' ' << mx << '\n';
    }
    else if (xp > max(xs, xe)) {
        cout << 2 << '\n';
        cout << mn << ' ' << ys << '\n';
        cout << mn << ' ' << ye << '\n';
    }
    else if (xp < min(xs, xe)) {
        cout << 2 << '\n';
        cout << mx << ' ' << ys << '\n';
        cout << mx << ' ' << ye << '\n';
    }
    else if (ys > ye) {
        cout << 4 << '\n';
        cout << xs << ' ' << mx << '\n';
        cout << mx << ' ' << mx << '\n';
        cout << mx << ' ' << mn << '\n';
        cout << xe << ' ' << mn << '\n';
    }
    else {
        cout << 4 << '\n';
        cout << xs << ' ' << mn << '\n';
        cout << mx << ' ' << mn << '\n';
        cout << mx << ' ' << mx << '\n';
        cout << xe << ' ' << mx << '\n';
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
