#include <bits/stdc++.h>
using namespace std;

void solve() {
    char a, b, c;
    cin >> a >> b >> c;

    cout << a;
    cout << (a > c ? '>' : a < c ? '<' : '=');
    cout << c << '\n';
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
