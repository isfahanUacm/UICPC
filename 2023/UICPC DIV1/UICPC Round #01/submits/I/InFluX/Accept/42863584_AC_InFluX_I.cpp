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

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2")

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
    ll n;
    cin >> n;

    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll sum[n], sumSqure[n];
    sum[0] = a[0];
    sumSqure[0] = a[0] * a[0];

    for (ll i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        sumSqure[i] = sumSqure[i - 1] + a[i] * a[i];
    }

    ll ans = sumSqure[0] * (sum[n - 1] - sum[0]);
    for (ll i = 1; i < n; i++)
    {
        if (sumSqure[i] * (sum[n - 1] - sum[i]) > ans)
            ans = sumSqure[i] * (sum[n - 1] - sum[i]);
    }

    cout << ans;
    return 0;
}
