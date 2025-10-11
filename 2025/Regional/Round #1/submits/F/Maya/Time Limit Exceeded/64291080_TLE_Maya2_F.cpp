#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int t;
    cin >> t;

    vector<int64_t> v = {0};
    const int B = 1e3;
    int64_t tot = 0, sum = 0;
    for (int i = 1; i <= B; i++) {
        sum = sum + 2 * i - 1;
        tot += sum;
        v.push_back(tot);
        if (tot > 1e18) {
            break;
        }
    }
    
    for (int i = 0; i < t; i++) {
        int64_t n;
        cin >> n;
        int ind = lower_bound(v.begin(), v.end(), n) - v.begin();
        int64_t reach = v[ind - 1];
        int x = 1, inc = 1, ans = (ind - 1) * (ind - 1);
        while (reach < n) {
            reach += x;
            x += inc;
            if (x == ind) {
                inc = -1;
            }
            ans++;
        }
        cout << "Case " << i + 1 << ": " << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("army.in", "r", stdin);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
