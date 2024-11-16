#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using str = string;

template <class T>
using pqg = priority_queue<T>;
template <class T>
using pql = priority_queue<T, vector<T>, greater<T>>;

const ll inf = 1e18;
const ll MOD = 1e9 + 7;
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
#define lb lower_bound
#define ub upper_bound
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <typename T>
bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
    return 0;
}

#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

void solve()
{
    vector<ll> p;
    p.pb(1);

    for (int i = 0; i <= 53 + 1; i++)
        for (int j = 0; j <= 53 + 1; j++)
            for (int a = 0; a <= 17 + 1; a++)
                for (int b = 0; b <= 17 + 1; b++)
                    if (i + j + a + b >= 0 and i / 3 + j / 2 + a + b < 25)
                    {
                        multiset<ll> digit;

                        ll t = i, t1, t2;
                        while (t >= 3)
                            digit.insert(8), t -= 3;
                        while (t >= 2)
                            digit.insert(4), t -= 2;
                        t1 = t;

                        t = j;
                        while (t >= 2)
                            digit.insert(9), t -= 2;
                        t2 = t;

                        t = a;
                        while (t >= 1)
                            digit.insert(5), t--;

                        t = b;
                        while (t >= 1)
                            digit.insert(7), t--;

                        if (t1 * t2 == 1)
                            digit.insert(6);
                        else if (t1 != 0)
                            digit.insert(2);
                        else if (t2 != 0)
                            digit.insert(3);

                        string pq = "";

                        while (!digit.empty())
                        {
                            ll u = *digit.begin();
                            digit.erase(digit.begin());
                            pq.pb('0' + u);
                        }

                        if (sz(pq) < 18 and !pq.empty())
                            p.pb(stoull(pq));
                    }
    sort(all(p));

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n <= 10)
            cout << n << endl;
        else if(n == 25) cout << 11 << endl;
        else
        {
            ll l = 0, r = sz(p) - 1, ans = -1;
            while (l <= r)
            {
                ll m = (l + r) / 2;
                if (p[m] <= n)
                    ans = max(m, ans), l = m + 1;
                else
                    r = m - 1;
            }
            cout << ans + 3 << endl;
        }
    }
}

int32_t main()
{
    fastio;

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}