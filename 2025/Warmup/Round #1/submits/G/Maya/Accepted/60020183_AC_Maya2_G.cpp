#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, n;
    cin >> w >> n;

    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());

    int64_t gold = 0;
    int i = 0;
    set<array<int, 2>> s;
    vector<int> ans;
    while (gold < w) {
        while (i < n && a[i][0] <= gold) {
            s.insert({a[i][1], a[i][2]});
            i++;
        }
        if (s.empty()) {
            cout << -1 << '\n';
            return;
        }
        ans.push_back((*s.rbegin())[1]);
        gold += (*s.rbegin())[0]; 
        s.erase(--s.end());
    }

    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
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
