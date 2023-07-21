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
#define sz(x) (ll)x.size()
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

const int maxN = 1e5 + 10;

vector<int> adj[maxN];
bool mark[maxN];
vector<int> component;

void DFS(int v)
{
    mark[v] = true;
    component.push_back(v);

    for (auto u : adj[v])
        if (!mark[u])
            DFS(u);
}

int main()
{
    fastio;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        if (mark[i])
            continue;
        component.clear();

        DFS(i);

        res += (sz(component) * (sz(component) - 1) / 2);
    }

    ld aim = 1.0 * res / (n * (n - 1) / 2.0);
    cout << fixed << showpoint << setprecision(16) << aim;
}
