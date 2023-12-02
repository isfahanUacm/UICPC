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

vi in(5000, 0), out(5000, 0);
vector<bool> vis(5000, false);
int g[5000][5000];

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < i; j++)
        {
            if (s[j] == '1')
                g[i][j] = 1;
            else
                g[j][i] = 1;
        }
    }

    int k = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j])
                out[j]++;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int val = 5005, idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && val >= out[j] - in[j])
            {
                val = out[j] - in[j];
                idx = j;
            }
        }

        vis[idx] = true;

        for (int j = 0; j < n; j++)
            if (g[idx][j])
                out[j]--;

        for (int j = 0; j < n; j++)
        {
            if (g[j][idx] == 1)
                in[j]++;
        }

        k += out[idx] - in[idx];

        res = max(res, k);
    }

    cout << res;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
