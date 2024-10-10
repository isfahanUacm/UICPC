#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, h;
    cin >> w >> h;

    cout << (w == h ? "Square" : "Rectangle") << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
