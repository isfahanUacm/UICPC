#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    for (int i = 0; i < 100; i++) {
        cin >> s;
    }
    if (s.back() == '0') {
        cout << 10 << '\n';
    } else {
        cout << s.back() << '\n';;
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
