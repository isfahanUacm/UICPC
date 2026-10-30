#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(int n, int m, int k) {
    if (k <= n)
        cout << k << '\n';
    else if (m % 2) {
        if ((n * m) % 2 == k % 2) {
            cout << n << '\n';
            return;
        } else {
            cout << n - 1 << '\n';
            return;
        }
    } else {
        if (k > n * (m - 1)) {
            cout << n - (k - n * (m - 1)) << '\n';
            return;
        } else
            solve(n, m - 1, k);
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        solve(n, m, k);
    }
    return 0;
}