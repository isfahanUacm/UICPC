#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
using pll = pair<long long, long long>;
using ull = unsigned long long;
#define ff first
#define all(x) (x).begin(), (x).end()
#define ss second
#define MP make_pair
#define pb push_back
#define pf push_front
#define MOD ((ll)1e9 + 7)
#define set_dec(x) cout << fixed << setprecision(x);
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const int MAXN = 1e5 + 5;
vector<pii> adj[MAXN];
ll dp[MAXN], a[MAXN], car[MAXN];
ll ans = 0, b, nm;
void dfs(int u, int p)
{
    ll cs = 0;
    for (auto pp : adj[u])
    {
        int v = pp.ff, w = pp.ss;
        if (v != p)
        {
            dfs(v, u);
            cs += car[v];
            dp[u] += dp[v] + abs(car[v]) * w;
        }
    }
    a[u] += cs;
    int cb = b;
    if (nm && a[u] > b)
    {
        cb++;
        nm--;
    }
    car[u] = a[u] - cb;
}
int main()
{
    fast int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        ll s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
            adj[i].clear();
        }
        b = s / n;
        nm = s - b * n;
        for (int i = 0; i < n - 1; i++)
        {
            int fi, se, w;
            cin >> fi >> se >> w;
            adj[fi].pb({se, w});
            adj[se].pb({fi, w});
        }
        fill(dp, dp + n + 1, 0);
        fill(car, car + n + 1, 0);
        dfs(1, 0);
        cout << dp[1] << endl;
    }
}