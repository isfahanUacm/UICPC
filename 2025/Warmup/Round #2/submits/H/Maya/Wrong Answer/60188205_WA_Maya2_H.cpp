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

    vector<int> cnt(21);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> aa = {12, 6, 18, 9, 3, 15, 5, 2, 4, 8, 16, 4, 14, 10, 20}, a, b = {1, 19, 17, 13, 11};
    for (int i = 0; i < (int)aa.size(); i++) {
        if (cnt[aa[i]]) {
            a.push_back(aa[i]);
        }
    }
    sort(a.begin(), a.end());

    int best = 0, last = -1;
    int64_t ans = 0;
    for (int i = 0; i < (int)b.size(); i++) {
        if (cnt[b[i]]) {
            if (last != -1) {
                ans += gcd(last, b[i]);
            }
            last = b[i];
        }
    }
    do {
        int v = 0;
        if (!a.empty() && last != -1) {
            v = gcd(a[0], last);
        }
        for (int i = 1; i < (int)a.size(); i++) {
            v += gcd(a[i], a[i - 1]);
        }
        if (v > best) {
            best = v;
        }

    } while (next_permutation(a.begin(), a.end()));

    ans += best;
    for (int i = 1; i <= 20; i++) {
        if (cnt[i]) {
            ans += (int64_t)(cnt[i] - 1) * i;
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
