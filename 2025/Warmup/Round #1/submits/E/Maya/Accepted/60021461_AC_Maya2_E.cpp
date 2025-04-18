#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    auto work = [&](int x) {
        int res = 1;   
        for (int i = 1; i < n; i++) {
            if (abs(h[i] - h[i - 1]) > x) {
                res++; 
            }
        }
        return res;
    };

    int lo = 0, hi = 1e9 + 1, ans = -1;
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        int w = work(mid);
        if (w <= m) {
            hi = mid;
        }
        else {
            lo = mid;
        }
        if (w == m) {
            ans = mid;
        }
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
