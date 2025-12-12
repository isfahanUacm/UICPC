#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
//#define int ll

const ll mod = 1e9 + 7;

long long extendedGcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extendedGcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extendedGcd(a, m, x, y);
    if (g != 1) {
        // Inverse does not exist
        return -1;
    } else {
        // Ensure x is positive
        return (x % m + m) % m;
    }
}

ll f(ll n)
{
    n %= mod;
    ll otp = n;
    otp *= (n+1) % mod;
    otp %= mod;
    otp *= (2*n + 1) % mod;
    otp %= mod;
    otp *= modInverse(6, mod);
    otp %= mod;
    return otp;
}

void solve()
{
    ll x; cin >> x;
    ll m = x + 1;
    m %= mod;
    ll n = (2 * m) % mod;

    ll ans = f(n) - 4*f(m) - 1;
    cout << ((ans % mod) + mod) % mod;
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<5; i++) cout << f(i) << endl;

    return 0;
}
