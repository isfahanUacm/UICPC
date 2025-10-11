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

    deque<int> q;
    for (int i = 1; i <= n; i++) {
        if ((n + i) % 2 == 0) {
            q.push_back(i);
        } else {
            q.push_front(i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << q[i] << " \n"[i == n - 1];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cubes.in", "r", stdin);

    int t = 1;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ":\n";
        solve();
    }

    return 0;
}
