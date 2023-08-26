#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;
#define nl "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define F first
#define S second
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

ll modOp(ll a, ll b, int op)
{
    switch (op)
    {
    case 0:
        return ((a % MOD) + (b % MOD)) % MOD;
    case 1:
        return ((a % MOD) - (b % MOD) + MOD) % MOD;
    case 2:
        return (a % MOD) * (b % MOD) % MOD;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<pii> r;

    int St = 150;
    vector<vector<ld>> dp(n + 1, vector<ld>(St + 1, 0.0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        r.pb({u, v});
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int s = 1; s <= St; s++)
        {
            dp[i][s] = dp[i - 1][s];
            if (s - r[i - 1].first >= 0)
            {
                dp[i][s] = max(dp[i][s], dp[i - 1][s - r[i - 1].first] * r[i - 1].second / 100.0);
            }
        }
    }

    ld res = 0;
    for (int i = 76; i <= 150; i++)
    {
        res = max(res, dp[n][i]);
    }

    cout << fixed << showpoint << setprecision(8) << res * 100 << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
