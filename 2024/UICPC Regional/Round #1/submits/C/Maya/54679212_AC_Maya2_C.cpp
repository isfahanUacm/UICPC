#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string a; cin >> a;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == '1') {
            ans++;
        } else if (i-1 >=0 && a[i-1] == '1') {
            ans++;
        } else if (i-2>=0 && a[i-2] == '1') {
            ans++;
        }
    }
    cout << ans << "\n";
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
