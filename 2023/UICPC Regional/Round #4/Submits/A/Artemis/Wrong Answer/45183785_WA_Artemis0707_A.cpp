#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx  = 2010;
long double tree[mx];
long double dp[mx][mx];
ll n;
long double tl,w;
long double d;
double dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double solve(ll l, ll r){
    
    if(dp[l][r] > -1 + 1e-5) return dp[l][r];
    if(l + r == n) return dp[l][r] =0;
    double ans = 1e10;
    if(l <= n/2)
        ans = min(ans,solve(l+1,r) + dist(tree[l+r],0.0,l*d,0.0));
    if(r <= n/2)
        ans = min(ans, solve(l,r+1) + dist(tree[l+r],0.0,r*d,w));

    return dp[l][r] = ans;
}


int main(){
    for(ll i=0;i<mx;i++)for(ll j=0;j<mx;j++)dp[i][j] = -1;
    
    cin >> n >> tl >> w;
    for(ll i=0;i<n;i++){
        cin >> tree[i];
    }  
    d = tl / (n/2 - 1);
    sort(tree,tree+n);
    double f = solve(0,0);
    cout << setprecision(10) << f << '\n';
    return 0;
    

}