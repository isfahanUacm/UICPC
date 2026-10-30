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


int comp[mxn];
int dis[mxn];
vector<int> adj[mxn];
void dfs(int u, int p){
    dis[u]=dis[p]+1;
    comp[u]=comp[p];
    for (auto v:adj[u]){
        if (v!=p) dfs(v,u);
    }
}
signed main(){
    FastIO
    int tc;
    cin>>tc;
    while(tc--){
        int n, m;
        cin>>n>>m;
        int a, b, c;
        cin>>a>>b>>c;
        FOR(i,1,m){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        comp[0]=1;
        dfs(c,0);
        comp[0]=2;
        if (comp[c]!=comp[a]) dfs(a,0);
        if ((comp[a]==2&&comp[b]==0) || (comp[b]==1&&comp[a]==2&&dis[b]==2)) cout<<"Tie\n";
        else if ((comp[a]==2&&comp[b]==2) || (comp[a]==1&&comp[b]==0) || (comp[b]==1&&comp[a]==2&&dis[b]>2)) cout<<"Alice\n";
        else{
            if (dis[a]<dis[b]) cout<<"Alice\n";
            else if (dis[a]>dis[b]) cout<<"Bob\n";
            else cout<<"Tie\n";
        }
        FOR(i,0,n){
            adj[i].clear();
            comp[i]=dis[i]=0;
        }
    }
}