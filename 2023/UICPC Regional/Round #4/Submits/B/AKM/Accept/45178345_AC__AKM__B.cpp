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
    ll n, b;
    cin >> n >> b;

    vector<unsigned long long int> p2(b + 1);
    p2[0] = 1;
    for (int i = 1; i <= b; i++)
        p2[i] = p2[i - 1] * 2;

    vector<unsigned long long int> ps(b + 1);
    ps[0] = 1;
    for (int i = 1; i <= b; i++)
        ps[i] = ps[i - 1] + p2[i];

    if (n > ps[b])
        cout << "no";
    else
        cout << "yes";
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
