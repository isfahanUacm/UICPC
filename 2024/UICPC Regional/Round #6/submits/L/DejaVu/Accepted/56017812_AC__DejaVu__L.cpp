#include <bits/stdc++.h>
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

const int N = 2e5 + 1;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vl> s(n + 2, vl(m + 2, -1)), p(n + 2, vl(m + 2, -1));

    for (int i = 0; i < m + 2; i++)
        s[0][i] = s[n + 1][i] = 0;
    for (int i = 0; i < n + 2; i++)
        s[i][0] = s[i][m + 1] = 0;

    for (int i = 0; i < n + 2; i++)
        for (int j = 0; j < m + 2; j++)
            cin >> p[i][j];

    bool valid = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll ans = 0;
            for (int k = i - 1; k <= i + 1; k++)
                for (int z = j - 1; z <= j + 1; z++)
                    if (k >= 0 and k <= n + 1 and z >= 0 and z <= m + 1)
                        ans += s[k][z];

            ans -= s[i + 1][j + 1];
            s[i + 1][j + 1] = p[i][j] - ans;
            if (s[i + 1][j + 1] > 1 or s[i + 1][j + 1] < 0)
            {
                valid = false;
            }
        }
    }

    for (int i = 0; i < n + 2; i++)
        for (int j = 0; j < m + 2; j++)
        {
            ll ans = 0;
            for (int k = i - 1; k <= i + 1; k++)
                for (int z = j - 1; z <= j + 1; z++)
                    if (k >= 0 and k <= n + 1 and z >= 0 and z <= m + 1)
                        ans += s[k][z];
            if (p[i][j] != ans)
                valid = false;
        }

    if (valid)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++) {
                if(s[i][j] == true) cout << "X";
                else cout << ".";
            }
            cout << endl;
        }
    }
    else
        cout << "impossible" << endl;
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
