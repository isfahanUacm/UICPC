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
    int w, h, n;
    cin >> w >> h >> n;

    vector<pair<int, int>> s1, s2;
    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
                s1.pb({i, j});
        }
    }

    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
                s2.pb({i, j});
        }
    }

    vector<pii> pp(n);
    for (int i = 0; i < n; i++)
        cin >> pp[i].F >> pp[i].S;

    bool f = true;
    for (int i = 0; i < n; i++)
    {
        int x = pp[i].F, y = pp[i].S;
        if (f)
        {
            bool p = false;
            for (pair<int, int> &t : s2)
            {
                if (t.S == x && t.F == y)
                {
                    s2.erase(find(all(s2), t));
                    p = true;
                    break;
                }
            }

            if (p)
            {
                if (s2.empty())
                {
                    f = false;
                }
            }
            else
            {
                f = false;
            }
        }
        else
        {
            bool p = false;
            for (pair<int, int> &t : s1)
            {
                if (t.S == x && t.F == y)
                {
                    s1.erase(find(all(s1), t));
                    p = true;
                    break;
                }
            }

            if (p)
            {
                if (s1.empty() && s2.empty())
                {
                    break;
                }
                else if (s1.empty())
                {
                    break;
                }
            }
            else
            {
                if (s1.empty() && s2.empty())
                {
                    break;
                }
                else if (s2.empty())
                {
                    break;
                }
                else
                {
                    f = true;
                }
            }
        }
    }

    if (s1.empty() && s2.empty())
        cout << "draw";
    else if (s1.empty())
        cout << "player two wins";
    else if (s2.empty())
        cout << "player one wins";
    else
        cout << "draw";

    cout << nl;
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
