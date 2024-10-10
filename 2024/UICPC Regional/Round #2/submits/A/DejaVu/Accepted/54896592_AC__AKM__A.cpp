#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
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

const int mxn = 3e5 + 4;
vector<vl> nums(10);
vector<vector<ld>> dp(10), ps(10);

void solve()
{
    for (int i = 1; i <= 9; i++)
    {
        vl p;
        for (int j = 1; j <= i; j++)
            p.pb(j);

        do
        {
            str q;
            for (int j = 0; j < i; j++)
                q.pb(p[j] + '0');
            nums[i].pb(stol(q));

        } while (next_permutation(all(p)));

        ll m = sz(nums[i]);

        dp[i].pb(1.0);
        ps[i].pb(1.0);

        for (int j = m - 2; j >= 0; j--)
        {
            dp[i].pb(ps[i].back() / m);
            ps[i].pb(ps[i].back() + dp[i].back());
        }

        reverse(all(dp[i]));
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll x;
        cin >> x;

        str y = to_string(x);
        map<char, char> mpx;
        vector<char> px;
        for (char u : y)
            px.pb(u);
        sort(all(px));
        ll cnt = 0;
        for (char u : px)
            mpx[u] = cnt + '1', cnt++;
        str fi;
        for (char u : y)
            fi.pb(mpx[u]);

        x = stol(fi);

        ll n = sz(to_string(x));

        ll idx = lower_bound(all(nums[n]), x) - nums[n].begin();
        ld ans = dp[n][idx];
        if (idx == sz(nums[n]) - 1)
            ans = 0.0;
        cout << fixed << showpoint << setprecision(9) << ans << endl;
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#else
    fastio
#endif

    int t = 1;
    while (t--)
        solve();

    return 0;
}