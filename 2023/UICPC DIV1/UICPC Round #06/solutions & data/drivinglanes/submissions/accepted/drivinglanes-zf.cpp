#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

#define MAXN 260
#define MAXM 260

using namespace std;

typedef long long ll;

const ll INF = (1ll<<60);

ll dp[MAXN][MAXM];
ll len[MAXN], c[MAXN], s[MAXN], k, r;
int n, m;

ll solve(int i, int l) {
    ll& val = dp[i][l];
    if (val == -1) {
        dp[i][l] = INF;
        if (i == n-1 && k*l <= len[i]) val = r*l + len[i];
        else if (i < n-1)
            for (int ll = 0; ll < m; ++ll)
                if (abs(ll-l)*k <= len[i])
                    val = min(val, r*abs(ll-l) + len[i] + c[i]*(ll+1) + s[i] + solve(i+1, ll));
    }

    return val;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> k >> r;
    for (int i = 0; i < n; ++i) cin >> len[i];
    for (int i = 0; i < n-1; ++i) cin >> s[i] >> c[i];

    cout << solve(0, 0) << endl;

    return 0;
}
