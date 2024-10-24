#include <bits/stdc++.h>
using namespace std;

void solve() {
    int d;
    cin >> d;

    if (d >= 7) {
        cout << "1 2 3\n";
    }
    else {
        cout << "7 27 47\n";
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
