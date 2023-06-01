#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll mod = 1e9 + 7;

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

ll mul(ll a, ll b)
{
    return (a % mod) * (b % mod) % mod;
}

ll min(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll sum(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    fastio;
    int n;
    cin >> n;

    vector<pii> a;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(mp(x, y));
    }

    sort(all(a));

    vector<ll> psS(n, 0);
    psS[0] = a[0].F + a[0].S;
    for (int i = 1; i < n; i++)
    {
        psS[i] = psS[i - 1] + a[i].F + a[i].S;
    }

    ll aim = 0;
    for (int i = 0; i < n; i++)
    {
        aim += (psS[n - 1] - psS[i]) - (n - 1 - i) * (a[i].F + a[i].S);
    }

    cout << aim;

    return 0;
}
