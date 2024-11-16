#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using str = string;

template <class T>
using pqg = priority_queue<T>;
template <class T>
using pql = priority_queue<T, vector<T>, greater<T>>;

const ll inf = 1e18;
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
#define lb lower_bound
#define ub upper_bound

template <typename T>
bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <typename T>
bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

const int N = 1000 + 1, logN = 25;
vector<pl> g[N][N];
pl par[logN][N][N];
int h[N][N];

vl dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

void dfs(pl u, pl p)
{
    par[0][u.F][u.S] = p;
    for (pl v : g[u.F][u.S])
    {
        if (v != p)
        {
            h[v.F][v.S] = h[u.F][u.S] + 1;
            dfs(v, u);
        }
    }
}

pl lca(pl u, pl v)
{
    if (h[u.F][u.S] < h[v.F][v.S])
        swap(u, v);

    int x = h[u.F][u.S] - h[v.F][v.S];

    for (int i = logN - 1; i >= 0; i--)
    {
        if ((x >> i) && 1)
        {
            u = par[i][u.F][u.S];
            x = h[u.F][u.S] - h[v.F][v.S];
        }
    }

    if (u == v)
        return u;

    for (int i = logN - 1; i >= 0; i--)
    {
        if (par[i][u.F][u.S] != par[i][v.F][v.S])
            u = par[i][u.F][u.S], v = par[i][v.F][v.S];
    }

    return par[0][u.F][u.S];
}

int dist(pl u, pl v)
{
    pl LCA = lca(u, v);
    return h[u.F][u.S] + h[v.F][v.S] - 2 * h[LCA.F][LCA.S];
}

void solve()
{
    for (int k = 0; k < logN; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                par[k][i][j] = {-1, -1};

    ll n, m;
    cin >> n >> m;
    cin.ignore();


    vector<str> s(n + 1);
    for (int i = 0; i < n + 1; i++)
        getline(cin, s[i]);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sz(s[i]); j += 2)
        {
            if (s[i][j] != '|')
            {
                if(s[i][j - 1] != '|')
                    g[i][j / 2 + 1].pb({i, (j / 2 + 1) - 1});
                if(s[i][j + 1] != '|')
                    g[i][j / 2 + 1].pb({i, (j / 2 + 1) + 1});
                if(s[i][j] != '_')
                    g[i][j / 2 + 1].pb({i + 1, j / 2 + 1});
                if(s[i - 1][j] != '_')
                    g[i][j / 2 + 1].pb({i - 1, j / 2 + 1});
            }
        }
    }

    ll q;
    cin >> q;
    vpl p(q);
    for (int i = 0; i < q; i++)
        cin >> p[i].F >> p[i].S;

    dfs(p[0], {-1, -1});

    for (int k = 1; k < logN; k++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (par[k - 1][i][j].F != -1)
                    par[k][i][j] = par[k - 1][par[k - 1][i][j].F][par[k - 1][i][j].S];
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i < q; i++)
    {
        ll x = dist(p[i - 1], p[i]);
        ans += x;
    }

    cout << ans << endl;
}

int32_t main()
{
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#else
    fastio
#endif

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}


