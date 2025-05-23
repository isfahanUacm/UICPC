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
    int n, T;
    cin >> n >> T;

    priority_queue<pair<double, int>, vector<pair<double, int>>> s;
    vector<tuple<double, double, double>> q(n);
    vector<double> t(n, 0.0);

    for (int i = 0; i < n; i++)
    {
        double a, b, c;
        cin >> a >> b >> c;

        q[i] = make_tuple(a, b, c);
        s.push({b, i});
    }

    for (int i = 0; i < 1e5; i++)
    {
        pair<double, int> u = s.top();
        s.pop();

        t[u.second] += 1.0 * T / 1e6;
        s.push({2 * get<0>(q[u.S]) * t[u.S] + get<1>(q[u.S]), u.S});
    }

    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += (get<0>(q[i]) * t[i] * t[i] + get<1>(q[i]) * t[i] + get<2>(q[i]));
    }

    cout << res / n;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
