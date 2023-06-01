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

ll pS(vector<int> &a)
{
}

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<int> s(n);
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> a[i];
    }

    sort(all(a));
    sort(all(s));

    ll aim = 0;

    ll sumS = 0;
    for (int i = 0; i < n; i++)
    {
        aim += (s[i] * i) - sumS;
        sumS += s[i];
    }

    ll sumA = 0;
    for (int i = 0; i < n; i++)
    {
        aim += (a[i] * i) - sumA;
        sumA += a[i];
    }

    cout << aim;

    return 0;
}
