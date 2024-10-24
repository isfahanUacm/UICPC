#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> s;
    for (int i = 1; i < N; i++) {
        s.insert(s.end(), i);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.erase(a[i]);
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        x--;

        auto it = s.upper_bound(a[x]);
        int v = *it;
        s.erase(it);
        s.insert(a[x]);
        a[x] = v;
        cout << a[x] << '\n';
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
