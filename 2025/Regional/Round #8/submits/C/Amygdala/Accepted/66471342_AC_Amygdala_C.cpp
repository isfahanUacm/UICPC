#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

ll f(ll a, ll b)
{
    ll otp = 0;
    for(ll i=1; i<=a; i++)
    {
        for(ll j=1; j<=b; j++)
        {
            otp += i * j;
        }
    }

    return otp;
}


void solve()
{
    ll n; cin >> n;
    while(n)
    {
        cout << f(n , n) << '\n';
        cin >> n;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<10; i++) cout << f(i, i) << endl;

    return 0;
}