#include <bits/stdc++.h>
using namespace std;
#define nl '\n';
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n), mn(n), mx(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    mn[n-1] = 0, mx[n-1] = a[n-1];
    for (int i=n-2; i>=0; i--) {
        mn[i] = max<long long>(0, a[i]-mx[i+1]);
        mx[i] = a[i]-mn[i+1];
    }
    if (mx[0] < 0) {
        cout << 0 << nl;
    } else {
        cout << mx[0]-mn[0]+1 << nl;
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
