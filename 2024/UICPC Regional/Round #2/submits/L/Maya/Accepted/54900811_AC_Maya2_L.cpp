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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> win(1001);
    int sum = n - 1;
    bool f = 0;
    for (int i = 1; i <= 1000; i++) {
        if (i <= sum) {
            win[i] = f;
        }
        else {
            f ^= 1;
            win[i] = f;
            sum += f ? n * (n - 2) : (n - 2);
            sum++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (win[a[i]]) {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
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
