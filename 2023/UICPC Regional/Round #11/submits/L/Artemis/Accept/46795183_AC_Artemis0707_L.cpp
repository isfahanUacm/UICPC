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
    while (cin >> s)
    {
        set<char> total;
        for (char c : s)
            total.insert(c);

        set<string> res;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                res.insert(s.substr(i, j - i + 1));
            }
        }
        res.erase(s);

        ll aim = 0;
        for (string u : res)
        {
            char first = u.front();
            char last = u.back();
            bool valid = true;

            set<char> chars;
            for (char c : u)
                chars.insert(c);

            if (sz(chars) != sz(total))
                continue;

            for (int i = 1; i < sz(u); i++)
            {
                if (first == u[i])
                {
                    valid = false;
                    break;
                }
            }
            for (int i = 0; i < sz(u) - 1; i++)
            {
                if (last == u[i])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
                aim++;
        }

        cout << aim << endl;
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
