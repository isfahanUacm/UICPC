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
#define int ll


const int N = 2e5+9;


void solve()
{
   int n, q;    cin >> n >> q;
    vector<int> v(n);
   for(int i=0; i<n; i++){
       cin >> v[i];
   }
   sort(v.begin(),v.end());
   while(q--){
       int l,r; cin >> l >> r;
       int i = upper_bound(v.begin(),v.end(), r) - v.begin();
       int j = upper_bound(v.begin(),v.end(),l-1) - v.begin();
       cout << i-j << '\n';
   }
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

    return 0;
}
