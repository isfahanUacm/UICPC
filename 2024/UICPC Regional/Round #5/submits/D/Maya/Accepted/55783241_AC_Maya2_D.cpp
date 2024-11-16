#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    cout << 62 << '\n';
    for (int i = 0; i < 30; i++) {
        cout << "B" << 2 * i + 1 << " = B" << 2 * i << " << " << min(n, 1 << i) << '\n';;
        cout << "B" << 2 * i + 2 << " = B" << 2 * i << " | B" << 2 * i + 1  << '\n';;
    }
    cout << "B61 = B60 << 1\n";
    cout << "B62 = B60 ^ B61\n";
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
