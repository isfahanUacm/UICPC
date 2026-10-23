#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,aaaa,bbbb) for(int i=aaaa;i<=bbbb;i++)
#define FORR(i,aaaa,bbbb) for(int i=aaaa;i>=bbbb;i--)
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define lg 31
#define mxn 300005
#define mxa 1000006
const long long inf=LLONG_MAX/5;

int pw(int a, int b){
    if (b==0) return 1;
    return pw(a*a%998244353, b/2)*(b%2?a:1)%998244353;
}
int dp[mxn], dp2[mxn][2];
vector<int> adj[mxn];
void dfs(int u, int p){
    if (adj[u].size()==1&&p!=-1){
        dp[u]=dp2[u][1]=1;
        dp2[u][0]=0;
        return;
    }
    dp[u]=1;
    int tmp=1;
    for (auto v:adj[u]){
        if (v==p) continue;
        dfs(v,u);
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        dp[u]*=dp2[v][0]+dp2[v][1];
        dp[u]%=998244353;
        tmp=(tmp*(dp2[v][0]+dp2[v][1]))%998244353;
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        dp2[u][0]+=tmp*pw(dp2[v][0]+dp2[v][1],998244353-2)%998244353 * dp[v];
        dp2[u][0]%=998244353;
        dp2[u][1]+=dp2[v][0];
        dp2[u][1]%=998244353;
    }
}
signed main(){
    FastIO
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        FOR(i,1,n-1){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,-1);
        // FOR(i,1,n) cout<<dp[i]<<" ";
        // cout<<"\n";
        // FOR(i,1,n) cout<<dp2[i][0]<<" ";
        // cout<<"\n";
        // FOR(i,1,n) cout<<dp2[i][1]<<" ";
        // cout<<"\n";
        cout<<(dp2[1][0]+dp2[1][1])%998244353<<"\n";
        FOR(i,1,n+1){
            dp[i]=0;dp2[i][0]=0;dp2[i][1]=0;adj[i].clear();
        }
    }
}