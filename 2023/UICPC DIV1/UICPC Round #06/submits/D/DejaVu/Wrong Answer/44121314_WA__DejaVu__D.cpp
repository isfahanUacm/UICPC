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
    int n;
    cin >> n;

    vector<ll> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(all(s));

    int r = 0, l = 10;

    ll res = 0;
    while (r <= l)
    {
        ll mid = (l + r) / 2;
        auto t = lower_bound(all(s), mid);

        if (s.end() - t >= mid)
        {
            res = mid;
            r = mid + 1;
        }
        else
            l = mid - 1;
    }

    cout << res;
    return 0;
}
