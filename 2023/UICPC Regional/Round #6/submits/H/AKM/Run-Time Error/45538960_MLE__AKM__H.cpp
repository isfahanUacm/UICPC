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
    int h, w;
    cin >> h >> w;

    int a, b;
    cin >> a >> b;

    vector<vi> grid(h, vi(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vl> ps(h + 1, vl(w + 1, 0));
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            ps[i][j] = grid[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }

    vector<double> res;
    for (int i = 0; i < h; i++)
    {
        for (int j = i; j < h; j++)
        {
            for (int k = 0; k < w; k++)
            {
                for (int p = k; p < w; p++)
                {
                    int s = (j - i + 1) * (p - k + 1);
                    ll val = ps[j + 1][p + 1] - ps[j + 1][k] - ps[i][p + 1] + ps[i][k];
                    if (s >= a && s <= b)
                        res.pb(1.0 * val / s);
                }
            }
        }
    }

    sort(all(res));
    int q = sz(res);

    cout << fixed << showpoint << setprecision(6) << ((q % 2 == 0) ? (res[q / 2] + res[q / 2 - 1]) / 2.0 : res[q / 2]);
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
