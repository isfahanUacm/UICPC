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
// #define int unsigned int
#define endl '\n'



void solve()
{
    ll a, b;
    cin >> a >> b;
    // cout << (int)(a * b) << endl;

    int a1 = 0;
    while(a) a = a >> 1, a1++;

    int a2 = 0;
    while(b) b = b >> 1, a2++;

    int a3 = a1 + a2 - 1;

    // cout << a1 << ' ' << a2 << ' ' << a3 << endl;

    int b1;
    if(a1 > 31)
    {
        if(a1 > 63) b1 = 128;
        else b1 = 64;
    }
    else b1 = 32;

    int b2;
    if(a2 > 31)
    {
        if(a2 > 63) b2 = 128;
        else b2 = 64;
    }
    else b2 = 32;

    int b3;
    if(a3 > 31)
    {
        if(a3 > 63) b3 = 128;
        else b3 = 64;
    }
    else b3 = 32;

    if(b1 < b3 && b2 < b3)
    {
        if(b1 < b2) b2 = b3;
        else b1 = b3;
    }

    cout << b1 << '\n' << b2 << '\n' << b3 << endl;
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