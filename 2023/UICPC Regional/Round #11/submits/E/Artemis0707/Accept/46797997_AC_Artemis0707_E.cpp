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
    double tr, tf;
    cin >> tf >> tr;

    double s;
    vector<double> be;
    while (cin >> s)
    {
        be.pb(s);

        int f = floor(s);
        int c = ceil(s + pow(10, -9));

        if (s > 0 && s < 1)
        {
            cout << 1;
            cout << endl;

            continue;
        }
        if (s == 0)
        {
            cout << 0;
            cout << endl;

            continue;
        }

        if (s < f + tf)
        {
            cout << f;
        }
        else if (s > f + tr)
        {
            cout << c;
        }
        else
        {
            double rec = 0.0;
            for (int i = sz(be) - 1; i >= 0; i--)
            {
                if (f + tr < be[i] || be[i] < f + tf)
                {
                    rec = be[i];
                    break;
                }
            }

            if (rec > f + tr)
                cout << c;
            else
                cout << f;
        }

        cout << endl;
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
