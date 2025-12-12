#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;

    vector a(q, vector<int>());
    while (q--) {
        int op;
        cin >> op;
        if (op == 2) {
            int i, x;
            cin >> i >> x;
            i--;
            a[i].push_back(x);
        } else if (op == 3) {
            int i, j;
            cin >> i >> j;
            i--, j--;
            cout << a[i][j] << '\n';
        }
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
