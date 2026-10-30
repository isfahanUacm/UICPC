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
    if(n == 0) return 1;

    int rec = f(a, (n-1)/2);
    rec += rec * a; rec %= MOD;
    if(!(n&1)) rec += my_pow(a, one_count(n));

    rec %= MOD;
    return  rec;
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