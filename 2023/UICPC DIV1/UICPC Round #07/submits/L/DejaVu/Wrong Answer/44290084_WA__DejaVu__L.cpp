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

void dfs(int u, vector<int> &comp, vector<bool> &st, vector<vector<int>> &adj)
{
    st[u] = true;
    comp.push_back(u);

    for (int v : adj[u])
    {
        if (!st[v])
        {
            dfs(v, comp, st, adj);
        }
    }
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> st(n, false);
    vector<vector<int>> comps;

    for (int i = 0; i < n; i++)
    {
        if (!st[i])
        {
            vector<int> comp;
            dfs(i, comp, st, adj);
            comps.push_back(comp);
        }
    }

    ll res = 0;
    for (vi t : comps)
        res += (t.size() * (t.size() - 1) / 2);

    cout << fixed << showpoint << setprecision(8) << 1.0 * res / ((n * (n - 1) / 2.0));
    return 0;
}
