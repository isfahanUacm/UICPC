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

double E(int i, int n, int ai, double p)
{
    double otp = i;
    otp += (1/p - 1) * n;

    return otp + ai;
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n); vin(a);
    vector<double> p(n); vin(p);

    double mn = E(0, n, a[0], p[0]);
    for(int i=1; i<n; i++)
    {
        if(p[i] == 0) continue;
        mn = min(mn, E(i, n, a[i], p[i]));
    }

    cout << fixed << setprecision(9) << mn << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}