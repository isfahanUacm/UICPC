#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    auto ask = [&](string s) {
        cout << 1 << ' ' << s << endl;
        int cnt;
        cin >> cnt;
        return cnt;
    };

    int a = ask("1"), b = ask("10") + ask("11");
    cout << 0 << ' ' << n << ' ' << (a == b ? '0' : '1') << endl;
    int foo;
    cin >> foo;
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