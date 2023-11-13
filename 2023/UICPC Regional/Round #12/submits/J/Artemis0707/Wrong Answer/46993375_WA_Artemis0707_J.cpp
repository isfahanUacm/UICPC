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

ll comb(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0)
        return 1;

    if (k > n / 2)
        k = n - k;

    int c = 1;
    for (int i = 0; i < k; i++)
        c = c * (n - i) / (i + 1);

    return c;
}

double f(int x, int n, int p)
{
    return (1.0 * comb(x, 1) * comb(n, p - 1)) / (1.0 * comb(n + x, p));
}

void solve()
{
    int n, p;
    cin >> n >> p;
    int l = 1, r = n + 1;
    int m;

    while (l < r)
    {
        m = (l + r) / 2;
        double f1 = f(m, n, p);
        double f2 = f(m + 1, n, p);
        double f3 = f(m - 1, n, p);

        if (f1 >= f3 && f1 >= f2)
            break;

        if (f2 > f1)
            l = m + 1;
        else
            r = m;
    }

    cout << f(m, n, p);
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
