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

double dis(int x, int y, int a, int b)
{
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}

void solve()
{
    int n;
    cin >> n;

    int l, w;
    cin >> l >> w;

    vi fin;
    fin.pb(0);
    ld tmp = l / (n / 2 - 1);
    for (int i = 1; i < n / 2 - 1; i++)
    {
        fin.pb(fin[i - 1] + tmp);
    }
    fin.pb(l);

    vi s;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        s.pb(t);
    }

    sort(all(s));

    double res = 0.0;
    for (int i = 0; i < n; i += 2)
    {
        double tmp1 = dis(s[i], 0, fin[i / 2], 0);
        double tmp2 = dis(s[i + 1], 0, fin[i / 2], w);
        double tmp3 = dis(s[i + 1], 0, fin[i / 2], 0);
        double tmp4 = dis(s[i], 0, fin[i / 2], w);

        res += min(tmp1 + tmp2, tmp3 + tmp4);
    }

    cout << fixed << showpoint << setprecision(8) << res;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
