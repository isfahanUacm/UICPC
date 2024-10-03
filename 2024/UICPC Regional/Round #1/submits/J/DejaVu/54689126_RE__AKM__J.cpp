#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
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

const int mxn = 3e5 + 4;

int x[2], y[2], u[2];
vector<pii> s;
vector<vector<int>> g(300, vector<int>(300));

void print()
{
}

bool find_sc()
{
    vector<pii> pi;
    for (int i = 0; i < 300; i++)
        for (int j = 0; j < 300; j++)
            if (g[i][j] == 1)
            {
                u[0] = i, u[1] = j;
                return true;
            }

    return false;
}

void down();
void up();
void right();
void left();

void up()
{
    cout << "up" << endl;
    x[1]++;
    int p = x[0], q = x[1];
    if (g[p][q] == 1)
    {
        while (g[p][q] == 1)
            q++;
        g[p][q] = 1;
        g[x[0]][x[1]] = 0;
    }

    g[y[0]][y[1]] = 0;

    print();
}

void down()
{

    cout << "down" << endl;
    x[1]--;

    int p = x[0], q = x[1];
    if (g[p][q] == 1)
    {
        while (g[p][q] == 1)
            q--;
        g[p][q] = 1;
        g[x[0]][x[1]] = 0;
    }

    g[y[0]][y[1]] = 0;

    print();
}

void right()
{
    cout << "right" << endl;
    x[0]++;

    int p = x[0], q = x[1];
    if (g[p][q] == 1)
    {
        while (g[p][q] == 1)
            p++;
        g[p][q] = 1;
        g[x[0]][x[1]] = 0;
    }

    g[y[0]][y[1]] = 0;

    print();
}

void left()
{
    cout << "left" << endl;
    x[0]--;
    int p = x[0], q = x[1];

    if (g[p][q] == 1)
    {
        while (g[p][q] == 1)
            p--;
        g[p][q] = 1;
        g[x[0]][x[1]] = 0;
    }

    g[y[0]][y[1]] = 0;

    print();
}

void reach()
{
    if (u[0] > y[0])
    {
        while (x[0] <= u[0])
            right();
    }
    else if (u[0] <= y[0])
    {
        while (x[0] >= u[0])
            left();
    }

    while (x[1] < u[1])
        up();
    while (x[1] > u[1])
        down();

    while (x[0] > y[0] + 1)
        left();
    while (x[0] < y[0] - 1)
        right();

    if (x[0] > y[0] and x[1] > y[1])
        up(), left();

    if (x[0] > y[0] and x[1] < y[1])
        down(), left();

    if (x[0] < y[0] and x[1] > y[1])
        up(), right();

    if (x[0] < y[0] and x[1] < y[1])
        down(), right();

    while (x[1] > y[1] + 1)
        down();

    while (x[1] < y[1] - 1)
        up();

    g[y[0]][y[1]] = 0;
}

void solve()
{
    int n;
    cin >> n;

    cin >> x[0] >> x[1] >> y[0] >> y[1];
    x[0] += 150, x[1] += 150, y[0] += 150, y[1] += 150;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u += 150, v += 150;

        g[u][v] = 1;
    }

    print();

    while (find_sc())
    {
        reach();
    }
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
    while (t--)
        solve();

    return 0;
}
