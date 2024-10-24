#include <bits/stdc++.h>
using namespace std;

void solve() {
    int d;
    cin >> d;

    if (d >= 10) {
        cout << "1 2 3\n";
    }
    else {
        cout << "27 47 97\n";
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
