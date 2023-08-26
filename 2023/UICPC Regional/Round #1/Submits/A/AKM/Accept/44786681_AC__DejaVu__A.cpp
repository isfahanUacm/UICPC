#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll MOD = 1e9 + 7;
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

int indexx(int i, int j, int n)
{
    return i * n + j;
}

void dfs(int u, vector<bool> &statue, vector<vector<int>> &adj)
{
    statue[u] = true;
    for (int v : adj[u])
    {
        if (!statue[v])
        {
            dfs(v, statue, adj);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<ll>> ans(n, vector<ll>(n, 0));

    if (arr[0][0] == '.')
    {
        ans[0][0] = 1;
    }
    else
    {
        cout << "INCONCEIVABLE";
        return;
    }

    MOD = pow(2, 31) - 1;

    for (int i = 1; i < n; i++)
        if (arr[0][i] == '.')
            ans[0][i] = ans[0][i - 1];
        else
            break;

    for (int i = 1; i < n; i++)
        if (arr[i][0] == '.')
            ans[i][0] = ans[i - 1][0];
        else
            break;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == '.')
            {
                ans[i][j] = (ans[i - 1][j] + ans[i][j - 1]) % MOD;
            }
        }

    if (ans[n - 1][n - 1] > 0)
    {
        cout << ans[n - 1][n - 1] % MOD;
        return;
    }

    vector<vector<int>> adj(n * n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                if (i + 1 < n && arr[i + 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i + 1, j, n));
                if (j + 1 < n && arr[i][j + 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j + 1, n));
            }
            else if (i == n - 1 && j == 0)
            {
                if (i - 1 >= 0 && arr[i - 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i - 1, j, n));
                if (j + 1 < n && arr[i][j + 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j + 1, n));
            }
            else if (i == 0 && j == n - 1)
            {
                if (i + 1 < n && arr[i + 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i + 1, j, n));
                if (j - 1 >= 0 && arr[i][j - 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j - 1, n));
            }
            else if (i == n - 1 && j == n - 1)
            {
                if (i - 1 >= 0 && arr[i - 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i - 1, j, n));
                if (j - 1 >= 0 && arr[i][j - 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j - 1, n));
            }
            else if (i == 0)
            {
                if (i + 1 < n && arr[i + 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i + 1, j, n));
                if (j - 1 >= 0 && arr[i][j - 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j - 1, n));
                if (j + 1 < n && arr[i][j + 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j + 1, n));
            }
            else if (i == n - 1)
            {
                if (i - 1 >= 0 && arr[i - 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i - 1, j, n));
                if (j - 1 >= 0 && arr[i][j - 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j - 1, n));
                if (j + 1 < n && arr[i][j + 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j + 1, n));
            }
            else if (j == 0)
            {
                if (i - 1 >= 0 && arr[i - 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i - 1, j, n));
                if (j + 1 < n && arr[i][j + 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j + 1, n));
                if (i + 1 < n && arr[i + 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i + 1, j, n));
            }
            else if (j == n - 1)
            {
                if (i - 1 >= 0 && arr[i - 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i - 1, j, n));
                if (j - 1 >= 0 && arr[i][j - 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j - 1, n));
                if (i + 1 < n && arr[i + 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i + 1, j, n));
            }
            else
            {
                if (i - 1 >= 0 && arr[i - 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i - 1, j, n));
                if (j - 1 >= 0 && arr[i][j - 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j - 1, n));
                if (i + 1 < n && arr[i + 1][j] == '.')
                    adj[i * n + j].push_back(indexx(i + 1, j, n));
                if (j + 1 < n && arr[i][j + 1] == '.')
                    adj[i * n + j].push_back(indexx(i, j + 1, n));
            }
        }
    }

    vector<bool> st(n * n, false);
    dfs(0, st, adj);

    if (st[n * n - 1])
    {
        cout << "THE GAME IS A LIE";
    }
    else
        cout << "INCONCEIVABLE";
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
