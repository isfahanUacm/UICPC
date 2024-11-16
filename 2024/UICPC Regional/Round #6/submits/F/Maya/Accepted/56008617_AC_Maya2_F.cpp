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
    map<int, int> mp;
    int one0 = -1, one1 = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i + 1;
        if (a[i] == 1 && one0 == -1) {
            one0 = i + 1;
        }
        else if (a[i] == 1) {
            one1 = i + 1;
        }
    }

    vector<int> fib(31);
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 31; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    if (one0 != -1 && one1 != -1) {
        cout << one0 << ' ' << one1 << '\n';
        return;
    }

    for (int i = 1; i < 30; i++) {
        if (mp[fib[i]] && mp[fib[i + 1]]) {
            cout << mp[fib[i]] << ' ' << mp[fib[i + 1]] << '\n';
            return;
        }
    }
    cout << "impossible\n";
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
