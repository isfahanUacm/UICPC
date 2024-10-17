#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    string s;
    cin >> s;

    string s2 = s;
    sort(s2.begin(), s2.end());
    int n = s.size();
    dbg(s2, s);
    for (int i = 0; i < n; i++) {
        if (s[i] != s2[i]) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s2[j]) {
                    if (s[i] > s2[j]) {
                        cout << i + 1 << ' ' << j + 1 << '\n';
                    }
                    else {
                        cout << j + 1 << ' ' << i + 1 << '\n';
                    }
                    swap(s2[i], s2[j]);
                    break;
                }
            }
        }
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
