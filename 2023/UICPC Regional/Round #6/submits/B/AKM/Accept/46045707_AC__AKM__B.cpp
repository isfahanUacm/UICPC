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

    map<char, char> t;
    t['R'] = 'S';
    t['B'] = 'K';
    t['L'] = 'H';

    string res;
    for (int i = 0; i < int(s.length()); i++)
    {
        if (i < int(s.length()) - 2)
        {
            set<char> tmp;
            tmp.insert(s[i]);
            tmp.insert(s[i + 1]);
            tmp.insert(s[i + 2]);

            if (sz(tmp) == 3)
            {
                res.pb('C');
                i += 2;
                continue;
            }
        }

        res.pb(t[s[i]]);
    }

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
