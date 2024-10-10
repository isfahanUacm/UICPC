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
vector<ll> nums;

void solve()
{
    ll n;
    cin >> n;
    str s = to_string(n);
    vector<ll> a;
    for (int i = 0; i < sz(s); i++)
        a.pb(s[i] - '0');
    sort(all(a));

    do
    {
        str p;
        for (int i = 0; i < sz(s); i++)
            p.pb('0' + a[i]);
        nums.pb(stoi(p));
    } while (next_permutation(all(a)));

    sort(all(nums));
    ll m = sz(nums);

    vector<ld> dp(m), ps(m, 0);
    dp[m - 1] = 1.0;
    ps[m - 1] = 1.0;

    for (int i = m - 2; i >= 0; i--)
    {
        dp[i] = ps[i + 1] / m;
        ps[i] = ps[i + 1] + dp[i];
    }
    ll idx = -1;

    for (int i = m - 1; i >= 0; i--)
    {
        if (nums[i] == n)
            idx = i;
    }

    ld ans = dp[idx];
    if (idx == m - 1)
        ans = 0.0;

    cout << fixed << showpoint << setprecision(9) << ans << endl;

    nums.clear();
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
    cin >> t;
    while (t--)
        solve();

    return 0;
}