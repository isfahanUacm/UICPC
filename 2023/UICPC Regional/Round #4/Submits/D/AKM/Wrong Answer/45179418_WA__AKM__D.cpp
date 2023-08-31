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

void solve()
{
    int n, c;
    cin >> n >> c;

    vector<tuple<int, int, int>> s(c);
    for (int i = 0; i < c; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        s[i] = make_tuple(u, v, w);
    }

    int res = -1;

    for (int i = 1948; i < 2008; i++)
    {
        unordered_set<int> s1, s2;
        for (tuple<int, int, int> t : s)
        {
            if (get<2>(t) < i)
            {
                s1.insert(get<0>(t));
                s1.insert(get<1>(t));
            }
            else
            {
                s2.insert(get<0>(t));
                s2.insert(get<1>(t));
            }
        }

        bool valid = true;
        if (sz(s1) <= (2 * n / 3) && sz(s2) <= (2 * n / 3))
        {
            for (int j = 1; j <= 400; j++)
            {
                if (s1.find(j) != s1.end() && s2.find(j) != s2.end())
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                res = i;
                break;
            }
        }
    }

    if (res == -1)
        cout << "Impossible";
    else
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
