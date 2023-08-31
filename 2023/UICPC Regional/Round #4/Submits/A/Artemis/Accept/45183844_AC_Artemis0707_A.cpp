#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx  = 2010;
double tree[mx];
double dp[mx][mx];
ll n;
double tl,w;
double d;
double dist(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double solve(ll l, ll r){
    
    if(dp[l][r] == -1){
        if(l + r == n) return dp[l][r] = 0.0;
        double ans = 1e10;
        if(l < n/2)
            ans = min(ans,solve(l+1,r) + dist(tree[l+r],0.0,l*d,0.0));
        if(r < n/2)
            ans = min(ans, solve(l,r+1) + dist(tree[l+r],0.0,r*d,w));
        dp[l][r] = ans;
    }
    return dp[l][r];
    
    
}


int main(){
    for(ll i=0;i<mx;i++)
        for(ll j=0;j<mx;j++)
            dp[i][j] = -1;
    
    cin >> n >> tl >> w;
    for(ll i=0;i<n;i++){
        cin >> tree[i];
    }  
    d = tl / (n/2 - 1);
    sort(tree,tree+n);
    printf("%.12lf\n",solve(0,0));
    return 0;
    

}