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
        continue;

        vector dp(n, vector<int64_t>(4)); // 0, 1, even, odd
        if (s[0] == ')') {
            dp[0][0] = 1;
            dp[0][2] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '(') {
                if (s[i - 1] == ')') {
                    dp[i][1] = dp[i - 1][0];
                }
                dp[i][2] = dp[i - 1][3];
                dp[i][3] = dp[i - 1][2];
                if (good[i]) {
                    ans += dp[i][3]; 
                } else {
                    ans += dp[i][1];
                }
            } else { // ')'
                if (s[i - 1] == '(') {
                    dp[i][0] = dp[i - 1][1] + 1;
                } else {
                    dp[i][0] = 1; 
                }
                dp[i][2] = dp[i - 1][3] + 1;
                dp[i][3] = dp[i - 1][2];
            }
            dbg(i, ans);
        }
        dbg(s);
        dbg(dp);
        dbg(s);
        dbg(ans);

        dp.assign(n, vector<int64_t>(4)); // 0, 1, even, odd
        if (s[n - 1] == ')') {
            dp[n - 1][0] = 1;
            dp[n - 1][2] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '(') {
                if (s[i + 1] == ')') {
                    dp[i][1] = dp[i + 1][0];
                }
                dp[i][2] = dp[i + 1][3];
                dp[i][3] = dp[i + 1][2];
                if (good[i]) {
                    ans += dp[i][3]; 
                } else {
                    ans += dp[i][1];
                }
            } else { // ')'
                if (s[i + 1] == '(') {
                    dp[i][0] = dp[i + 1][1] + 1;
                } else {
                    dp[i][0] = 1; 
                }
                dp[i][2] = dp[i + 1][3] + 1;
                dp[i][3] = dp[i + 1][2];
            }
        }
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
