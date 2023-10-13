#include <bits/stdc++.h>
using namespace std;

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

    set<string> f, r;

    map<string, set<string>> s;
    map<string, set<string>> o;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;

        int n1, n2;
        cin >> n1;

        set<string> tmp2;
        vector<string> s1(n1);
        for (int j = 0; j < n1; j++)
        {
            cin >> s1[j];
            tmp2.insert(s1[j]);
        }

        cin >> n2;
        vector<string> s2(n2);

        set<string> tmp;
        for (int j = 0; j < n2; j++)
        {
            cin >> s2[j];
            tmp.insert(s2[j]);
        }

        for (int j = 0; j < n1; j++)
        {
            if (f.find(s1[j]) == f.end())
            {
                for (int k = 0; k < n2; k++)
                {
                    s[s1[j]].insert(s2[k]);
                }

                f.insert(s1[j]);
            }
            else
            {
                set<string> tmp3;
                for (string c : s[s1[j]])
                {
                    if (tmp.find(c) != tmp.end())
                    {
                        tmp3.insert(c);
                    }
                }
                s[s1[j]] = tmp3;
            }
        }

        for (int j = 0; j < n2; j++)
        {
            if (r.find(s2[j]) == r.end())
            {
                for (int k = 0; k < n1; k++)
                {
                    o[s2[j]].insert(s1[k]);
                }

                r.insert(s2[j]);
            }
            else
            {
                set<string> tmp3;
                for (string c : o[s2[j]])
                {
                    if (tmp2.find(c) != tmp2.end())
                    {
                        tmp3.insert(c);
                    }
                }
                o[s2[j]] = tmp3;
            }
        }
    }

    vector<pair<string, string>> res;
    for (string tmpp : f)
    {
        for (string y : s[tmpp])
        {
            if (o[y].find(tmpp) != o[y].end())
                res.pb({tmpp, y});
        }
    }

    sort(all(res));

    for (pair<string, string> y : res)
        cout << '(' << y.F << ", " << y.S << ')' << nl;

    cout << nl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
