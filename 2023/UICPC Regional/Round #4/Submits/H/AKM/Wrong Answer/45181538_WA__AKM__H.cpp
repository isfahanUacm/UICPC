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
const int mx = 1e9;

void solve()
{
    int c, n, a;
    cin >> c >> n >> a;

    deque<int> s[n];
    set<int> cache;

    multimap<int, int> last;

    int res = 0;
    int input = 0;
    for (int i = 0; i < a && sz(cache) != c; i++)
    {
        int t;
        cin >> t;
        res += (cache.find(t) == cache.end());
        cache.insert(t);
        input++;
    }

    vector<int> access;
    for (int i = 0; i < a - input; i++)
    {
        int t;
        cin >> t;
        access.pb(t);
        s[access[i]].push_back(i);
    }

    int idx = 1;
    for (int c : cache)
    {
        if (!s[c].empty())
        {
            last.insert({s[c].front(), c});
        }
        else
            last.insert({mx, c});
    }

    for (int i = 0; i < a - c; i++)
    {
        if (cache.find(access[i]) != cache.end())
        {
            s[access[i]].pop_front();
        }
        else if (cache.size() < c)
        {
            cache.insert(access[i]);
            s[access[i]].pop_front();

            if (!s[access[i]].empty())
                last.insert({s[access[i]].front(), access[i]});
            else
                last.insert({mx, access[i]});
        }
        else
        {
            auto tmp = last.end();
            tmp--;
            pii t = *tmp;

            cache.erase(t.second);
            last.erase(t.first);

            cache.insert(access[i]);
            s[access[i]].pop_front();

            if (!s[access[i]].empty())
                last.insert({s[access[i]].front(), access[i]});
            else
                last.insert({mx, access[i]});

            res++;
        }
    }

    cout << res;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
