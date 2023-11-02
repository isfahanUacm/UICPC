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
bool a[mxn], b[mxn];

void solve()
{
    double x1, x2;
    cin >> x1 >> x2;

    bool o = x1 > x2;

    if (o)
        x2 += 4.4;
    else
        x1 += 4.4;

    int n;
    cin >> n;
    priority_queue<int, vi, greater<int>> s;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        s.push(u);
    }

    bool f = false;
    for (int i = 0; i <= 1e6; i++)
    {
        if (!s.empty() && i == s.top())
        {
            f = !f;
            s.pop();
        }
        a[i] = f;
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        s.push(u);
    }

    f = false;
    for (int i = 0; i <= 1e6; i++)
    {
        if (!s.empty() && i == s.top())
        {
            f = !f;
            s.pop();
        }
        b[i] = f;
    }

    for (int i = 0; i <= 1e6; i++)
    {
        if (a[i])
            x1 += 1;
        if (b[i])
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

    if (!a[mxn - 1] && b[mxn - 1])
    {
        double y = x2 - x1;
        cout << "bumper tap at time " << ceil(y) << nl;
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
