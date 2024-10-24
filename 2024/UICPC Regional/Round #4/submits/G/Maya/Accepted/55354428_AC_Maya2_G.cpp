#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int64_t n;
    cin >> n;

    int num = int(log10(n)), num2 = 0;
    for (int i = 1; i < 10; i++) {
        string s(num + 1, '0' + i);
        if (n >= stoll(s)) {
            num2++;
        }
    }
    cout << num * 10 + num2 + (num == 0) << '\n';
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
