#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, D;
    cin >> n >> D;

    vector<int> cnt(n);
    for (int i = 0; i < D; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cnt[x]++; 
        cnt[y]++;
    }

    int mn = *min_element(cnt.begin(), cnt.end());
    int mx = *max_element(cnt.begin(), cnt.end());
    int num = 0;
    for (int i = 0; i < n; i++) {
        num += mx - cnt[i];
    }

    dbg(mn, mx, num);
    int ans = 0;
    if (mx - mn <= num / 2) {
        ans = num % 2 ? mx + 1 : mx;
    }
    else {
        int rem = ((mx - mn) - (num - (mx - mn)));
        ans = mx + (rem + n - 3) / (n - 2);
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
