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

const int mxn = 1e5;
vector<bool> prime(mxn, true);
vector<int> primes;

void sieve()
{
    for (int i = 2; i < 1e5; i++)
    {
        if (!prime[i])
            continue;

        primes.pb(i);
        for (int j = i + i; j < 1e5; j += i)
        {
            prime[j] = false;
        }
    }
}

void solve()
{
    sieve();
    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << "no";
        return;
    }

    set<int> q;
    for (int i = 0; i < sz(primes) && n > 1; i++)
    {
        if (n % primes[i] == 0)
        {
            q.insert(primes[i]);
        }
        while (n > 1 && n % primes[i] == 0)
        {
            n /= primes[i];
        }
    }

    if (n > 1)
        q.insert(n);

    if (sz(q) > 1)
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
