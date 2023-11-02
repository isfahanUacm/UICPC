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

const int mxn = 100;
map<string, vector<string>> g;
set<string> qs;
int id = 0;

void topologicalSortUtil(string u, map<string, bool> &visited, stack<string> &Stack)
{
    // Mark the current node as visited.
    visited[u] = true;

    for (string v : g[u])
    {
        if (!visited[v])
        {
            topologicalSortUtil(v, visited, Stack);
        }
    }

    Stack.push(u);
}

vector<string> topologicalSort()
{
    stack<string> Stack;

    map<string, bool> visited;
    for (string name : qs)
        visited[name] = false;

    for (string name : qs)
        if (!visited[name])
            topologicalSortUtil(name, visited, Stack);

    vector<string> aim;
    while (Stack.empty() == false)
    {
        aim.pb(Stack.top());
        Stack.pop();
    }

    return aim;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    qs.insert(s);

    map<string, vector<string>> fat;

    map<string, double> dp;

    for (int i = 0; i < n; i++)
    {
        string u, v, w;
        cin >> u >> v >> w;

        g[v].pb(u);
        g[w].pb(u);

        fat[u].pb(v);
        fat[u].pb(w);
    }

    vector<str> aim = topologicalSort();
    set<str> fo;
    for (string u : aim)
    {
        fo.insert(u);
    }

    dp[s] = 1.0 / 2.0;
    for (string u : aim)
    {
        if (u == s)
            continue;

        string v = fat[u][0];
        string w = fat[u][1];

        if (fo.find(v) == fo.end())
            dp[v] = 0;
        if (fo.find(w) == fo.end())
            dp[w] = 0;

        dp[u] = 1.0 * (dp[w] + dp[v]) / 2.0;
    }

    string res;
    double mx = 0.0;

    while (m--)
    {
        string name;
        cin >> name;
        if (mx <= dp[name])
        {
            mx = dp[name];
            res = name;
        }
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
