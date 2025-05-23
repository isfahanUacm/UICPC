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

vector<pii> r = {{1, 1}, {1, 0}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, 1}, {0, -1}};

unordered_map<string, int> words;

int idx(int i)
{
    if (i >= 4)
        i = 0;
    if (i < 0)
        i = 3;
    return i;
}

vector<string> g(4);
vector<vector<bool>> vis(4, vector<bool>(4, false));
string word;

void dfs(int i, int j)
{
    vis[i][j] = true;
    word.pb(g[i][j]);

    if (words.find(word) != words.end())
        words[word]++;

    if (word.length() > 8)
    {
        word.pop_back();
        return;
    }

    for (pii v : r)
    {
        if (!vis[idx(i + v.first)][idx(j + v.second)])
        {
            vis[idx(i + v.first)][idx(j + v.second)] = true;
            dfs(idx(i + v.first), idx(j + v.second));
            vis[idx(i + v.first)][idx(j + v.second)] = false;
        }
    }

    word.pop_back();
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string p;
        cin >> p;
        words[p] = false;
    }

    int t;
    cin >> t;

    vl fib(20);
    fib[3] = 1;
    fib[4] = 1;
    fib[5] = 2;
    fib[6] = 3;
    fib[7] = 5;
    fib[8] = 11;

    while (t--)
    {
        for (int i = 0; i < 4; i++)
            cin >> g[i];

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        vis[i][j] = false;

                word = "";
                dfs(i, j);
            }
        }

        ll score = 0;
        string mxW = "";
        int cnt = 0;
        for (pair<string, int> word : words)
        {
            if (word.first.size() > 2 && word.second)
            {
                score += fib[word.F.size()];
                cnt++;

                if (word.F.length() > mxW.length())
                    mxW = word.F;
            }

            words[word.F] = 0;
        }

        cout << score<< ' ' << mxW << ' ' << cnt << nl;
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
