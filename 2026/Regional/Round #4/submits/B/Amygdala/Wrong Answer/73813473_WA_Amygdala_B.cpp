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
#define int unsigned ll
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

int bit_difference(int p2, int b)
{
    while(b) b >>= 1, p2 >>= 1;

    int otp = 0;
    while(p2) otp++, p2 >>= 1;
    return otp;
}

map<int, int> pre_comp;

int f(int a, int n)
{
    if(n == 0) return 1;
    if(n == 1) return a + 1;
    if(pre_comp.find(n) != pre_comp.end()) return pre_comp[n];

    int p2 = 1;
    while(p2*2 < p2 || p2*2 <= n) p2 = p2 << 1;
    p2--;
    if(n == p2)
    {
        int rec = f(a, n/2);
        int ans = (rec + (rec*a) % MOD) % MOD;
        pre_comp[n] = ans;
        return ans;
    }

    int diff = n - p2 - 1;
    int rec1 = f(a, p2);
    int rec2 = (f(a, diff) * a) % MOD;

    int ans = (rec1%MOD + rec2%MOD) % MOD;
    pre_comp[n] = ans;
    return ans;
}

void solve()
{
    pre_comp.clear();
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