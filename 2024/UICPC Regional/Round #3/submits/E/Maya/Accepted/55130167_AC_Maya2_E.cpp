#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> s(n);
    vector<array<int, 3>> a(m);
    for (int i = 0; i < n; i++) {
        cin >> s[i][0];
        s[i][1] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i][1];
        a[i][2] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i][0];
    }

    sort(s.rbegin(), s.rend());
    sort(a.begin(), a.end());

    vector<bool> vis(m);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[j] && a[j][1] >= s[i][0]) {
                res[s[i][1]] = a[j][2];
                vis[j] = true;
                break;
            }
        }
    }
    if (count(vis.begin(), vis.end(), true) != n) {
        cout << "impossible\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] + 1 << " \n"[i == n - 1];
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
