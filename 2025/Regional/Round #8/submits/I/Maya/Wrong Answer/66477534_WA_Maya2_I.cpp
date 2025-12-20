#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m;
    while (true) {
        cin >> n;
        if (n == 0) {
            return;
        }

        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int m;
        cin >> m;

        vector<string> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        bool f = false;
        if (n == m) {
            for (int i = 0; i < n; i++) {
                for (int j = 0, k = i; j < m; j++) {
                    if (a[k] != b[j]) {
                        break;
                    }
                    k = (k + 1) % n;
                    if (k == i) {
                        cout << n + 2 << ' ' << 2 * n + 2 << '\n';
                        f = true;
                        break;
                    }
                }
                if (f) {
                    break;
                }
            }
        }
        if (f) {
            continue;
        }

        dbg(a, b);
        for (int i = n + m; i < n + m + min(n, m); i++) {
            cout << i << ' ';
        }
        cout << '\n';
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
