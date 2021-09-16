#include <bits/stdc++.h>
using namespace std;

bool vis[100003], vis2[100003];
vector<vector<int>> adj(100003);
vector<int> disjoint;
int n, l, a, b, d, md, ind=-1;
int par[100003];
void dfs(int u){
    vis[u]=true;
    if(md<d){
        ind = u;
        md = d;
    }
    for(auto v: adj[u])
        if(!vis[v]){
            d++;
            dfs(v);
            d--;
        }
}
void dfs2(int u){
    vis2[u]=true;
    if(md<d){
        md = d;
        ind = u;
    }
    for(auto v: adj[u]){
        if(!vis2[v]){
            d++;
            par[v]=u;
            dfs2(v);
            d--;
        }
    }
}
int main()
{
    cin>>n>>l;
    for (int i = 0; i < l; ++i) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mxid=0, mx=0;
    for (int i = 0; i < n; ++i) {
        if(!vis[i]){
            md = 0;
            d = 0;
            if(adj[i].size())
                dfs(i);
            else
                ind = i;
            md = 0;
            d = 0;
            if(adj[i].size())
                dfs2(ind);
            for (int i = 0; i < md/2+md%2; ++i) {
                ind = par[ind];
            }
            disjoint.push_back(ind);
            if(mx<md){
                mx = md;mxid=ind;
            }
        }
    }
    for (int i = 0; i < disjoint.size(); ++i) {
        if(disjoint[i]==mxid)continue;
        adj[mxid].push_back(disjoint[i]);
        adj[disjoint[i]].push_back(mxid);
    }
    fill_n(vis, n, false);fill_n(vis2, n, false);
    md = 0; d=0;
    dfs(mxid);
    md = 0; d=0;
    dfs2(ind);
    cout<<md<<endl;
    
    return 0;
}

