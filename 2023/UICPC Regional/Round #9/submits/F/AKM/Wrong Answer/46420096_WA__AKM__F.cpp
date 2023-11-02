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
#define nl '\n'
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
    string st;
    cin >> st;

    if (st.length() == 1)
    {
        cout << st;
        cout << nl;
        return;
    }
    else if (st == "22")
    {
        cout << st;
        cout << nl;
        return;
    }

    vector<pair<int, int>> s;
    for (char c : st)
        s.pb({(c - '0'), 1});

    vector<pair<int, int>> ns;
    int i = 0;
    while (i < s.size())
    {
        if (s[i].F != 2)
            ns.push_back(s[i]);
        else
        {
            if (i < s.size() - 1 && s[i + 1].F == 2)
            {
                ns.pb({4, 2});
                i += 1;
            }
            else
            {
                ns.pb({4, 2});
            }
        }
        i += 1;
    }

    s = ns;
    reverse(all(s));
    ns.clear();

    while (!s.empty())
    {
        pair<int, int> u = s.back();
        s.pop_back();

        if (u.F == 4)
        {
            if (s.empty())
                ns.pb({8, 2});

            else if (s.back().F == 4)
            {
                pair<int, int> v = s.back();
                s.pop_back();

                if (u.S == 1)
                {
                    if (v.S == 1)
                    {
                        ns.pb({8, 2});
                    }
                    else if (v.S == 2)
                    {
                        ns.pb({8, 4});
                    }
                }
                else if (u.S == 2)
                {
                    if (v.S == 1)
                    {
                        ns.pb({8, 3});
                    }
                    else if (v.S == 2)
                    {
                        ns.pb({8, 5});
                    }
                }
            }
        }
        else if (u.F == 8)
        {
            ns.pb(u);
        }
    }

    s = ns;
    int rem = pow(2, ceil(log2(1.0 * s.size())));
    rem -= s.size();

    for (int i = 0; i < rem; i++)
        s.pb({8, 1});

    for (pii x : s)
    {
        if (x.S == 1)
        {
            cout << 8;
        }
        else if (x.S == 2)
        {
            cout << 44;
        }
        else if (x.S == 3)
        {
            cout << 224;
        }
        else if (x.S == 4)
        {
            cout << 422;
        }
        else
        {
            cout << 2222;
        }
    }

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
