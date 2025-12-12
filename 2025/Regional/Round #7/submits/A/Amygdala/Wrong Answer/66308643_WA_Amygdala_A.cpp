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


const int N = 2e5+9;
int dp[N] , a[N];

void solve()
{
   int n , k;
   cin >> n >> k;
   for(int i=0 ; i<n ; i++){
       cin >> a[i];
   }
   dp[0]=max(0 , a[0]);
   for(int i=1 ; i<k ;i++){
       dp[i]=max(dp[i-1] , a[i]);
   }
   for(int i=k ; i<n ; i++){
       dp[i]=max(dp[i-1] , a[i]+dp[i-k]);
   }
   cout << dp[n-1] << endl;
}

int main()
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
