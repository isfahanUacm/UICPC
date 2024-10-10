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

void solve()
{
    ll q, m;
    cin >> q >> m;

    vector<vector<ll>> s(q, vl(4, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            char chose, status;
            cin >> chose >> status;
            if (status == 'F')
                s[j][chose - 'A'] = 0;
            else
                s[j][chose - 'A'] = 1;
        }
    }

    vector<char> ans;

    for (int i = 0; i < q; i++)
    {
        ll idx = -1;
        for (int j = 0; j < 4; j++)
            if (s[i][j] == 1)
                idx = j;

        if (idx != -1)
            ans.pb('A' + idx);
        else
        {
            ll cnt = 0;
            for (int j = 0; j < 4; j++)
                if (s[i][j] == 0)
                    cnt++;
            if (cnt == 3)
            {
                ll idxf = -1;
                for (int j = 0; j < 4; j++)
                    if (s[i][j] == -1)
                        idxf = j;

                ans.pb('A' + idxf);
            }
            else
                ans.pb('?');
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i];
        if (i < q - 1)
            cout << ' ';
        else
            cout << endl;
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
    cin >> t;
    while (t--)
        solve();

    return 0;
}
