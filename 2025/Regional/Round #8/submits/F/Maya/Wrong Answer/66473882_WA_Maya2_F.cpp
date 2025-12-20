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

        int64_t ans = 0;
        vector dp(n, vector<int64_t>(4)); // 0, 1, even, odd
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
