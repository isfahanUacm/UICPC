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

void dfs(int u, unordered_map<int, vi> &newAdj, unordered_map<int, bool> &st)
{
    st[u] = true;
    for (int v : newAdj[u])
    {
        if (!st[v])
            dfs(v, newAdj, st);
    }
}

void solve()
{
    int n;
    cin >> n;

    unordered_map<int, vi> adj;
    unordered_map<int, vi> adjR;
    unordered_map<int, bool> sta1, sta2;

    vi ord;
    int resss = -1;

    for (int i = 0; i < n; i++)
    {
        int m, t;
        cin >> m >> t;
        sta1[m] = false;
        sta2[m] = false;

        ord.push_back(m);
        for (int j = 0; j < t; j++)
        {
            int k;
            cin >> k;
            adj[m].push_back(k);
            adjR[k].push_back(m);
        }
    }

    dfs(0, adj, sta1);
    dfs(0, adjR, sta2);

    bool f = true;

    for (int i = 0; i < n; i++)
    {
        if (!sta2[ord[i]])
        {
            f = false;
            cout << "TRAPPED " << ord[i] << nl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!sta1[ord[i]])
        {
            f = false;
            cout << "UNREACHABLE " << ord[i] << nl;
        }
    }

    if (f)
        cout << "NO PROBLEMS";
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
