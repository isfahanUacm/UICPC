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

const int N = 2e5 + 1;

void solve()
{
    str s;
    cin >> s;

    map<str, ll> ans;
    stack<char> p;
    str first;
    int l = 0;

    for (int i = 0; i < sz(s); i++)
    {
        if (s[i] == ')')
        {
            p.pop();
        }
        else
            p.push(s[i]);

        if (p.empty())
        {
            ans[s.substr(l, i - l + 1)]++;
            if (l == 0)
                first = (*ans.begin()).F;

            l = i + 1;
        }
    }

    if (sz(ans) > 1)
    {
        for (pair<str, ll> u : ans)
            if (u.F != first)
            {
                cout << u.F;
                ans[u.F]--;
                break;
            }

        for (pair<str, ll> u : ans)
            for (int i = 0; i < u.S; i++)
                cout << u.F;
        cout << endl;
    }
    else
        cout << "no" << endl;
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