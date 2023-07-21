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

int main()
{
    fastio;
    int n, c;
    cin >> n >> c;

    vi a(n);
    vl ps(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            ps[i] = a[i];
        else
            ps[i] = ps[i - 1] + a[i];
    }

    vector<pii> res;
    int s = 0, e = 0;
    while (s < n)
    {
        res.push_back({s, e});
        if (e + 1 > n - 1)
            s++;
        else
        {
            if (s == 0)
                if (ps[e + 1] > c)
                    s++;
                else
                    e++;
            else if (ps[e + 1] - ps[s - 1] > c)
                s++;
            else
                e++;
        }
    }
    res.push_back({s, e});

    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        while (l < res.size() && res[l].second < i)
        {
            l++;
        }
        while (r < res.size() && res[r].first <= i)
        {
            r++;
        }

        cout << r - l << endl;
    }

    return 0;
}
