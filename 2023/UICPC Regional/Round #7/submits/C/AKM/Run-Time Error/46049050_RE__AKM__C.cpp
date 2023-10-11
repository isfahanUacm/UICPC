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
const int mxn = 1e5;
vi g[mxn];
vi deg1(mxn, 0);
vi deg2(mxn, 0);
vector<bool> del(mxn, false);

void solve()
{
    int n, m, o, d;
    cin >> n >> m >> o >> d;
    o--, d--;

    del[d] = true;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
        deg1[u]++;
        deg2[v]++;
        deg2[u]++;
        deg1[v]++;
    }

    queue<int> q;
    q.push(d);
    del[d] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (del[v])
                continue;

            deg1[v]--;
            if (deg1[v] <= deg2[v] / 2)
            {
                del[v] = true;
                q.push(v);
            }
        }
    }

    if (del[o])
        cout << "leave";
    else
        cout << "stay";
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
