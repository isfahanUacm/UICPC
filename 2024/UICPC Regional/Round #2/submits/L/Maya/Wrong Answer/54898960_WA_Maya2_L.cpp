#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> win(1001);
    for (int i = 1; i <= 1000; i++) {
        if (i < n) {
            win[i] = false;
        }
        else if (i <= n * (n - 1)) {
            win[i] = true;
        }
        else if (((i - (n * (n - 1))) / n) % 2 == 0) {
            win[i] = false;
        }
        else {
            win[i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (win[a[i]]) {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
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
