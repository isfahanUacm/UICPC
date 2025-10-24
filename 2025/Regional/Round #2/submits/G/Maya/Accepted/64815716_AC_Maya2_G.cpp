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
    dbg(n);

    string s, t;
    cin >> s >> t;

    string p;
    for (int i = 0; i < n / 2; i++) {
        int mn = 1e9;
        char mn_char = ' ';
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int num = 0;
            num += abs(s[i] - ch) + abs(t[i] - ch);
            num += abs(s[n - i - 1] - ch) + abs(t[n - i - 1] - ch);
            if (num < mn) {
                mn = num;
                mn_char = ch;
            }
        }
        p += mn_char;
    }
    if (n % 2) {
        int mn = 1e9;
        char mn_char = ' ';
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int num = 0;
            num += abs(s[n / 2] - ch) + abs(t[n / 2] - ch);
            if (num < mn) {
                mn = num;
                mn_char = ch;
            }
        }
        p += mn_char;
        p += string(p.rbegin() + 1, p.rend());
    } else {
        p += string(p.rbegin(), p.rend());
    }

    cout << p << '\n';
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
