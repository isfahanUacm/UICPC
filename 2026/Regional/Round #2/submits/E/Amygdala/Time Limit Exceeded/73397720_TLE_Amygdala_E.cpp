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

void solve()
{
    int n;  cin >>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    vecInt hash(1e6, 0);
    int kind = 0;
    for(auto x : v) {hash[x] ++; if(hash[x] == 1) kind++;}

    if(kind&1)
    {
        bool valid = false;
        for(auto x : hash) if(x > 1) {valid = true; break;}

        if(valid) {cout << "YES\n";}
        else cout << "NO\n";
    }
    else cout << "YES\n";
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