#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

const int N = 504;

void solve() {
    int d4, d6, d8, d12, d20;
    cin >> d4 >> d6 >> d8 >> d12 >> d20;

    int mn = d4 + d6 + d8 + d12 + d20;
    int sum = d4 * 4 + d6 * 6 + d8 * 8 + d12 * 12 + d20 * 20;

    vector<pair<double, int>> dp(N + 1);
    for (int i = 0; i < N + 1; i++) {
        dp[i] = {0, i};
    }
    dp[0] = {1, 0};
    auto calc = [&](int x, int num) {
        for (int j = 0; j < num; j++) {
            vector<pair<double, int>> dp2(N + 1);
            for (int i = 0; i < N + 1; i++) {
                dp2[i] = {0, i};
            }
            for (int i = 1; i <= x; i++) {
                for (int k = N; k >= 0; k--) {
                    if (k + i <= N) {
                        dp2[k + i].first += dp[k].first * ((double)1 / x);
                    }
                }
            }
            dp = dp2;
        }
    };
    calc(4, d4);
    calc(6, d6);
    calc(8, d8);
    calc(12, d12);
    calc(20, d20);


    sort(dp.begin() + mn, dp.begin() + sum + 1);
    for (int i = sum; i >= mn; i--) {
        cout << dp[i].second << " \n"[i == mn];
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
