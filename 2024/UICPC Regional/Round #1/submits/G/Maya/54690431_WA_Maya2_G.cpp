#include<bits/stdc++.h>
#ifndef LOCAL
#define LINE
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#else
#define LINE cerr << "----------" << nl;
#define fastio
#endif
using namespace std;
using ll = long long; using ld = long double;
#define nl '\n'
#define arr array
#define pb push_back

void solve() {
    int n, k; cin >> n >> k;
    vector<ld> p(n+1);
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end(), greater<ld>());
    vector dp(n+1, vector<ld>(n+1, 0));
    dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            if (j == 0) {
                dp[i][j] = (1-p[i-1])*dp[i-1][0];
            } else if (j == i) {
                dp[i][j] = p[i-1]*dp[i-1][j-1];
            } else {
                dp[i][j]  = (1-p[i-1])*dp[i-1][j] + p[i-1]*dp[i-1][j-1];
            }
            //cout << dp[i][j] << ' ' ;
        }
        //cout << nl;
    }

    /*
    ld t = 0;
    for (int right=0; right<=n; right++) {
        cout << dp[n][right] << nl;
        int wrong = n - right;
        if (right-wrong >= k) {
            t += dp[n][right];
        }
    }
    cout << t << nl;

    */
    ld ans = 0;
    for (int i=1; i<=n; i++) {
        ld res = 0;
        for (int right=0; right<=i; right++) {
            int wrong = i - right;
            if (right-wrong >= k) {
                res += dp[i][right];
            }
        }
        //cout << res << nl;
        ans = max(res, ans);
    }
    cout << fixed << setprecision(7) << ans << nl;
}

int32_t main() {
    fastio
    int t = 1;
cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}

