#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            return;
        }

        string s;
        cin >> s;

        int64_t ans = 0, even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')' && i % 2 == 0) {
                even++;
            } else if (s[i] == ')') {
                odd++;
            }
        }

        vector<bool> good(n);
        for (int i = 1; i < n; i++) {
            if (s[i] == '(' && s[i - 1] == '(') {
                good[i] = true;
            } else if (s[i] == '(' && (i - 2 >= 0 && s[i - 2] == '(')) {
                good[i] = good[i - 2];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '(' && s[i + 1] == '(') {
                good[i] = true;
            } else if (s[i] == '(' && (i + 2 < n && s[i + 2] == '(')) {
                good[i] = good[i + 2];
            }
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '(' && s[i - 1] == '(') {
                good[i] = true;
            } else if (s[i] == '(' && (i - 2 >= 0 && s[i - 2] == '(')) {
                good[i] = good[i - 2];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '(' && s[i + 1] == '(') {
                good[i] = true;
            } else if (s[i] == '(' && (i + 2 < n && s[i + 2] == '(')) {
                good[i] = good[i + 2];
            }
        }
        dbg(good);
        for (int i = 0; i < n; i++) {
            if (good[i] && i % 2 == 0) {
                ans += odd;
            } else if (good[i]) {
                ans += even;
            } else if (s[i] == '(') {
                int64_t num0 = 0, num1 = 0;
                if (i - 1 >= 0) {
                    num0++;
                }
                while (i < n) {
                    if (s[i] == '(') {
                        num1++;
                    } else {
                        i -= 2;
                        break;
                    }
                    i += 2;
                }
                if (i + 1 < n) {
                    num0++;
                }
                dbg(i, num0, num1);
                num0 += num1 - 1;
                ans += num1 * num0;
            }
            dbg(i, ans);
        }
        dbg(s);
        cout << ans << '\n';
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
