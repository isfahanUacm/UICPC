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
    string s;
    cin >> s;

    int n;
    cin >> n;

    map<char, int> x, y;
    vector<string> qs = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < sz(qs[i]); j++)
        {
            x[qs[i][j]] = i;
            y[qs[i][j]] = j;
        }
    }

    vector<pair<ll, string>> q;
    for (int i = 0; i < n; i++)
    {
        string p;
        cin >> p;

        ll res = 0;
        for (int j = 0; j < sz(p); j++)
        {
            res += (abs(x[p[j]] - x[s[j]]) + abs(y[p[j]] - y[s[j]]));
        }

        q.push_back({res, p});
    }

    sort(all(q));
    for (pair<ll, string> l : q)
        cout << l.S << ' ' << l.F << nl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
