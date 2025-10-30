#include <bits/stdc++.h>
using namespace std;

void solve() {
    int c, n;
    cin >> c >> n;

    if (c == n) {
        cout << c << '\n';
    } else if (c < n) {
        cout << c + 1 << '\n';
    } else {
        cout << 0 << '\n';
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
