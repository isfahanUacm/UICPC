#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ":" << x << "\n"
#define deb2(x) cout << ":" << x << "\n"
#define in(x) cin >> x
#define pb push_back
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define f first
#define s second
#define ll long long
#define per(i, a, b) for (ll i = a; i <= b; i++)
#define rep(i, a, b) for (ll i = a; i >= b; i--)
#define outl(x) cout << x << endl;
#define outc(x) cout << x << " ";
const ll maxn = 1e6 + 15;
const ll mod = 1e9 + 7;
const ll lg = 22;
void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    // Topological Sorting, O(n + m)
    // An order of vertices in DAG that every edge leads from
    // the vertex with a smaller index to a vertex with a larger one.
    vector<bool> vis(n);
    vector<ll> order;
    order.reserve(n);
    auto dfs = [&](auto &&self, ll v) -> void
    {
        vis[v] = true;
        for (auto u : adj[v])
        {
            if (!vis[u.f])
            {
                self(self, u.f);
            }
        }
        order.push_back(v);
    };
    auto topological_sorting = [&]() -> void
    {
        for (ll v = 0; v < n; v++)
        {
            if (!vis[v])
            {
                dfs(dfs, v);
            }
        }
        reverse(order.begin(), order.end());
    };
    topological_sorting();

    vector<ll> dist(n);
    ll mx = -1;
    for (ll i = n - 1; i >= 0; i--)
    {
        for (pii edge : adj[order[i]])
        {
            if (dist[edge.f] + edge.s > dist[order[i]])
                dist[order[i]] = dist[edge.f] + edge.s;
        }
        mx = max(mx, dist[order[i]]);
    }
    outl(mx);

    // for (ll i = 0; i < n; i++) {
    //     cout << order[i] + 1 << " \n"[i == n - 1];
    // }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}