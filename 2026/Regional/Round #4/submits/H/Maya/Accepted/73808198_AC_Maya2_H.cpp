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
    
    vector<int> a(n);
    int x = -1, cn2 = 0;
    bool f = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            cn2++;
            f = false;
            if (x == -1) {
                x = i;
            }
        }
    }


    if (f) {
        cout << 0 << '\n';
        return;
    }
    int cn = 0;
    for (int i = x; i < n; i++) {
        if (a[i] == a[x]) {
            cn++;
        } else {
            break;
        }
    }
    dbg(cn);
    if (cn2 == cn) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
