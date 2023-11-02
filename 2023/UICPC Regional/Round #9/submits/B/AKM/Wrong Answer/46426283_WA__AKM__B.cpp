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

const int mxn = 1e6 + 1;
int a[mxn], b[mxn];

void solve()
{
    int x1, x2;
    cin >> x1 >> x2;

    bool o = x1 > x2;

    if (o)
        x2 += 4;
    else
        x1 += 4;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        if (i % 2 == 0)
            a[u] = 1;
        else
            a[u] = 2;
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        if (i % 2 == 0)
            b[u] = 1;
        else
            b[u] = 2;
    }

    int val = 2;
    for (int i = 0; i <= 1e6; i++)
    {
        if (a[i] != 0)
            val = a[i];
        else
            a[i] = val;
    }

    val = 2;
    for (int i = 0; i <= 1e6; i++)
    {
        if (b[i] != 0)
            val = b[i];
        else
            b[i] = val;
    }

    for (int i = 0; i <= 1e6; i++)
    {
        if (a[i] == 1)
            x1 += 1;
        if (b[i] == 1)
            x2 += 1;

        if (o && x1 <= x2)
        {
            cout << "bumper tap at time " << i + 1 << nl;
            return;
        }
        else if (!o && x2 <= x1)
        {
            cout << "bumper tap at time " << i + 1 << nl;
            return;
        }
    }

    if (o && !a[mxn - 1] && b[mxn - 1])
    {
        int y = x1 - x2;
        cout << "bumper tap at time " << int(1e6) + ceil(y) << nl;
        return;
    }
    else if (!o && a[mxn - 1] && !b[mxn - 1])
    {
        int y = x2 - x1;
        cout << "bumper tap at time " << int(1e6) + ceil(y) << nl;
        return;
    }

    cout << "safe and sound" << nl;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
