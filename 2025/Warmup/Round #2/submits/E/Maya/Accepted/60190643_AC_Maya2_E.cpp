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

    vector<int> a(1 << 17);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int v = 0;
        for (auto ch : s) {
            v |= 1 << (ch - 'a');    
        }
        a[v] = 1;
    }

    for (int i = 0; i < (1 << 17); i++) {
        if (a[i]) {
            for (int j = 0; j < 17; j++) {
                a[i | (1 << j)] = 1;
            }
        }
    }

    string t;
    cin >> t;

    int m = t.size(), v = 0;
    int64_t ans = 0;
    vector<int> cnt(17);
    for (int i = 0, j = 0; i < m; i++) {
        while (j < m && !a[v]) {
            v |= 1 << (t[j] - 'a');
            cnt[t[j] - 'a']++;
            j++;
        }
        if (a[v]) {
            ans += m - j + 1;
        }
        cnt[t[i] - 'a']--;
        if (cnt[t[i] - 'a'] == 0) {
            v -= 1 << (t[i] - 'a');
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
