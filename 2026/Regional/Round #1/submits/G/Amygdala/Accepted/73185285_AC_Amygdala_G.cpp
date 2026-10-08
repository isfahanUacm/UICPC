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
// #define idddnt unsigned int
#define int ll
#define endl '\n'

void solve()
{
    ll n, q, k;    cin >> n >> q >> k;
    string s;   cin >> s;

    double t [3] = {5e8, 1e8, 2e7};
    int mem = 2e7;
    int ind = 0;
    if(s[0] == 'p')
        ind = 2;
    else if(s[0] == 'j')
        ind = 1;
    
    int ans = 0;

    ll cal = 2ll * n * q + k*n*5;
    ll m = k*n;
    if(cal > t[ind]){
        ans += 1;
    }
    if(m > mem){
        ans += 2;
    }

    if(ans == 0){
        cout << "OK\n";
    }else if(ans == 1){
        cout << "TL\n";
    }else if(ans == 2){
        cout << "ML\n";
    }else{
        cout << "TL and ML\n";
    }

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