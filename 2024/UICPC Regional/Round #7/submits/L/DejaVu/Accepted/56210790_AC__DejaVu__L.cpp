#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = (n + 1) / 2;
    ans += 2 * (n / 3);
    if (n % 3 == 1) {
        ans++;
    }
    else if (n % 3 == 2 && n % 2 == 0) {
        ans += 2;
    }
    else if (n % 3 == 2) {
        ans++;
    }
    cout << ans << '\n';
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