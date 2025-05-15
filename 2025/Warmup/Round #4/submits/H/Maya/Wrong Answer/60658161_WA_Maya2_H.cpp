#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;

    int S, F;
    cin >> S >> F;

    vector<int> b(n), e(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i] >> e[i]; 
    }
    sort(b.begin(), b.end());
    sort(e.begin(), e.end());

    vector<int> h(n + 1);
    int num = 0, pmn = S, pnum = 0;
    for (int i = 0, j = 0; i < n || j < n;) {
        int mn = min(i < n ? b[i] : int(1e9), e[j]);
        while (i < n && b[i] == mn) {
            num++;
            i++;
        }
        while (j < n && e[j] == mn) {
            num--;
            j++;
        }
        dbg(num);
        if (mn >= S && mn < F) {
            h[pnum] += mn - pmn;
            pmn = mn;
        }
        if (mn >= F && pmn != -1) {
            h[pnum] += F - pmn;
            pmn = -1;
        }
        pnum = num;
        dbg(i, j, num, h, mn);
    }

    for (int i = 0; i < n; i++) {
        h[i] += i != 0 ? h[i - 1] : 0;
        cout << h[i] << " \n"[i == n];
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
