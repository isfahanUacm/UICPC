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

vector<vector<int>> components;

void SCC(int u, vi &disc, vi &low, stack<int> &st, vector<bool> &stackMember, vector<vi> &adj)
{
    static int time = 0;

    disc[u] = low[u] = ++time;
    st.push(u);
    stackMember[u] = true;

    for (int v : adj[u])
    {
        if (disc[v] == -1)
        {
            SCC(v, disc, low, st, stackMember, adj);
            low[u] = min(low[u], low[v]);
        }
        else if (stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }

    int w = 0;
    if (low[u] == disc[u])
    {
        vector<int> cmp;
        while (st.top() != u)
        {
            w = st.top();
            cmp.push_back(w);
            stackMember[w] = false;
            st.pop();
        }
        w = st.top();
        stackMember[w] = false;
        st.pop();
        cmp.push_back(w);
        components.push_back(cmp);
    }
}

void dfs(int u, vector<unordered_set<int>> &newAdj, vector<bool> &st)
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

    vi disc(n, -1), low(n, -1);
    stack<int> st;
    vector<bool> stackMember(n, false);
    vector<vi> adj(n, vi());

    vi ord;

    for (int i = 0; i < n; i++)
    {
        int m, t;
        cin >> m >> t;

        ord.push_back(m);

        for (int j = 0; j < t; j++)
        {
            int k;
            cin >> k;
            adj[m].push_back(k);
        }
    }

    for (int i = 0; i < n; i++)
        if (disc[i] == -1)
            SCC(i, disc, low, st, stackMember, adj);

    unordered_map<int, int> compV;

    for (int i = 0; i < sz(components); i++)
        for (int t : components[i])
            compV[t] = i;

    vector<unordered_set<int>> newAdj(sz(components), unordered_set<int>());
    for (int i = 0; i < n; i++)
    {
        for (int u : adj[i])
        {
            if (compV[i] == compV[u])
                continue;
            newAdj[compV[i]].insert(compV[u]);
        }
    }

    vector<bool> sta(n, false);
    dfs(compV[0], newAdj, sta);

    bool f = true;

    for (int i = 0; i < n; i++)
    {
        if (compV[ord[i]] == compV[ord[0]])
            continue;
        else if (!sta[compV[ord[i]]])
        {
            cout << "UNREACHABLE " << ord[i] << nl;
            f = false;
        }
        else
        {
            cout << "TRAPPED " << ord[i] << nl;
            f = false;
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
