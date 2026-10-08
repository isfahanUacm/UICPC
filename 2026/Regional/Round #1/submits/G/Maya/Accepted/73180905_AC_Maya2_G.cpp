#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n, q, k;
    cin >> n >> q >> k;

    string lang;
    cin >> lang;

    int64_t calc = n * q * 2 + n * k * 5;
    int64_t mem = n * k;

    bool tl = false, ml = false;
    if (lang == "cpp" && calc > 5e8) {
        tl = true;
    }
    if (lang == "java" && calc > 1e8) {
        tl = true;
    }
    if (lang == "py" && calc > 2e7) {
        tl = true;
    }
    if (mem > 2e7) {
        ml = true;
    }

    if (!tl && !ml) {
        cout << "OK\n";
    } else if (tl && ml) {
        cout << "TL and ML\n";
    } else if (tl) {
        cout << "TL\n";
    } else {
        cout << "ML\n";
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
