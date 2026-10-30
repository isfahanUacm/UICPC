#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n)
#define sint(s) string (s); cin >> (s)
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n'
#define int ll
// #define endl '\n'

int MOD = 998244353ll;

int one_count(int n)
{
    int otp = 0;
    while(n)
    {
        otp += (int)(n&1);
        n = n >> 1;
    }
    return otp;
}

int my_pow(int a, int b)
{
    if(b == 0) return 1;

    int rec = my_pow(a, b/2);
    rec *= rec; rec %= MOD;
    if(b&1) rec *= a;

    rec %= MOD;
    return rec;
}

int f(int a, int n)
{
    // cout << "going for " << a << ' ' << n << endl;
    if(n == 0) return 1;
    if(n == 1) return a + 1;
    // if(n == 2) return (2*a + 1) % MOD;

    int p2 = 1;
    while(p2*2 <= n) p2 = p2 << 1;
    p2--;
    if(n == p2)
    {
        int rec = f(a, n/2);
        return (rec + (rec*a)%MOD) % MOD;
    }
    // p2 = p2 >> 1;

    // cout << "p2 = " << p2 << endl;

    int diff = n - p2 - 1;
    int rec1 = f(a, p2);
    int rec2 = f(a, diff) * a;

    // cout << "FOUND " << rec1 << ' ' << rec2 << endl;

    return (rec1 + rec2%MOD)%MOD;
}

void solve()
{
    int n, m; cin >> n >> m;
    cout << f(n, m) << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}