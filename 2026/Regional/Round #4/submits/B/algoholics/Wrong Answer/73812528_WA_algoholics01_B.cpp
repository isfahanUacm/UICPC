#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,aaaa,bbbb) for(int i=aaaa;i<=bbbb;i++)
#define FORR(i,aaaa,bbbb) for(int i=aaaa;i>=bbbb;i--)
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define lg 31
#define mxn 1000006
#define mxa 1000006
const long long inf=LLONG_MAX/5;

#define mod 998244353
int pw(int a, int b){
    if (b==0) return 1;
    return pw(a*a%mod, b/2)*(b%2?a:1)%mod;
}
int solve(int n, int m){
    if (m==0) return 1;
    int ans=0;
    ans+=pw(n+1, 63-__builtin_clzll(m));
    ans%=mod;
    // cout<<"::: "<<ans<<"\n";
    ans+=n*solve(n,m - (1ll<<(63-__builtin_clzll(m))))%mod;
    ans%=mod;
    return ans%mod;
}
signed main(){
    FastIO
    // cout<<(1ll<<(63-__builtin_clzll(12ll)));
    int tc;
    cin>>tc;
    while(tc--){
        int n, m;
        cin>>n>>m;
        cout<<solve(n,m)%mod<<"\n";
    }
}