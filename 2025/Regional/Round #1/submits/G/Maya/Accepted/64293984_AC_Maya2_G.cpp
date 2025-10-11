#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    cout << (n % 3 ? "Bakkar" : "Wahdan") << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("jenga.in", "r", stdin);

    int t = 1;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ": ";
        solve();
    }

    return 0;
}
