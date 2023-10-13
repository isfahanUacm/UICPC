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
    int n, q;
    cin >> n >> q;

    string s;
    for (int i = 0; i < n; i++)
        s.pb('-');
    vector<vector<string>> star(n + 1, vector<string>());
    bool fg = true;

    for (int i = 0; i < q; i++)
    {
        int idx;
        cin >> idx;
        idx--;

        string p;
        cin >> p;

        if (!fg)
            continue;

        if (p.find("*") == -1)
        {
            for (int j = 0; j < sz(p); j++)
            {
                if (p[j] != '.')
                {
                    if (s[idx + j] == '-')
                        s[idx + j] = p[j];
                    else if (s[idx + j] != p[j])
                    {
                        cout << "IMPOSSIBLE" << nl;
                        fg = false;
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < sz(p); j++)
            {
                if (p[j] == '*')
                {
                    string qq = p.substr(j + 1);
                    if (qq.empty())
                        continue;
                    star[idx + 1].pb(qq);
                    break;
                }

                if (p[j] != '.')
                {
                    if (s[idx + j] == '-')
                        s[idx + j] = p[j];
                    else if (s[idx + j] != p[j])
                    {
                        cout << "IMPOSSIBLE" << nl;
                        fg = false;
                    }
                }
            }
        }
    }

    if (!fg)
        return;

    for (int i = 0; i < n; i++)
    {
        for (string j : star[i])
        {
            if (s.find(j, i) == -1)
            {
                cout << "IMPOSSIBLE" << nl;
                return;
            }
        }
    }

    if (s.find('-') == -1)
        cout << s << nl;
    else
        cout << "IMPOSSIBLE" << nl;
        
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
