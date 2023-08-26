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
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    int dif = g - s;
    if (dif == 0)
        cout << 0;
    else if (u == 0 && dif > 0)
        cout << "use the stairs";
    else if (d == 0 && dif < 0)
        cout << "use the stairs";
    else if (u == 0 && d == 0)
        cout << "use the stairs";

    else
    {
        int gc = __gcd(u, d);
        if (abs(dif) % gc == 0)
        {
            if (dif > 0)
            {
                int res = dif / u;
                dif = dif % u;
                res += (dif / gc) * 2;
                cout << res;
            }
            else
            {
                dif = abs(dif);
                int res = dif / d;
                dif = dif % d;
                res += (dif / gc) * 2;
                cout << res;
            }
        }
        else
        {
            cout << "use the stairs";
        }
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
