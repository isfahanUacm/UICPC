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
    int n;
    cin >> n;

    vector<string> s(n);
    map<char, int> mpc;
    mpc['h'] = 0;
    mpc['s'] = 0;
    mpc['d'] = 0;
    mpc['c'] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        mpc[s[i][1]]++;
    }

    vector<char> ps = {'s', 'h', 'd', 'c'};
    vector<int> p = {1, 2, 3, 4};

    ll aim = n * n;
    do
    {
        ll res = 0;
        int j = 0;
        for (int i = 0; i < 4; i++)
        {
            if (mpc[ps[i]] == 0)
                continue;

            int cnt = 0;
            vector<char> q, r, e;
            for (int k = j + 1; k < j + mpc[ps[i]] && k < n; k++)
            {
                if (s[k][1] == ps[i])
                {
                    j = k, cnt++;
                    q.pb(s[k][0]);
                    r.pb(s[k][0]);
                    e.pb(s[k][0]);
                }
            }

            res += mpc[ps[i]] - cnt;
            sort(all(r), greater<char>());
            sort(all(e));

            int inc = 0, dc = 0;

            for (int i = 0; i < sz(q); i++)
            {
                if (q[i] != e[i])
                    inc++;
                if (q[i] != r[i])
                    dc++;
            }

            res += min(dc, inc);
        }

        aim = min(aim, res);

    } while (next_permutation(p.begin(), p.end()));

    cout << aim  - 1;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
