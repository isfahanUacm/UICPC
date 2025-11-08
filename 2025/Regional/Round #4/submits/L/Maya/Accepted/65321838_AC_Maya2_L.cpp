#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    array<int, 3> ans;
    ans[0] = a[0] / 3;
    ans[1] = a[1] - 2 * ans[0];
    ans[2] = a[n - 1] / 3;

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
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
