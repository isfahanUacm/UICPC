#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n, q, k;
    cin >> n >> q >> k;

    string s;
    cin >> s;

    int64_t tl = n * (2 * q + 5 * k);
    int64_t ml = n * k;

    int64_t tlc = 0, mlc = 2e7;
    if (s == "cpp") {
        tlc = 5e8; 
    } else if (s == "java") {
        tlc = 1e8;
    } else {
        tlc = 2e7;
    }

    if (tl > tlc && ml > mlc) {
        cout << "TL and ML\n";
    } else if (tl > tlc) {
        cout << "TL\n";
    } else if (ml > mlc) {
        cout << "ML\n";
    } else {
        cout << "OK\n";
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
