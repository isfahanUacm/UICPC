#include <bits/stdc++.h>
using namespace std;

bool vis[2503], vis2[2503];
vector<vector<int>> adj(2503);
vector<pair<int, int>> edges;
vector<int> disjoint;
bool joint[2503][2503];
int n, a, b, d, md, ind=-1;
int par[2503];
void dfs(int u){
    vis[u]=true;
    if(md<d){
        ind = u;
        md = d;
    }
    for(auto v: adj[u]){
        if(!joint[u][v])
            continue;
        if(!vis[v]){
            d++;
            dfs(v);
            d--;
        }
    }
}
void dfs2(int u){
    vis2[u]=true;
    if(md<d){
        md = d;
        ind = u;
    }
    for(auto v: adj[u]){
        if(!joint[u][v])
            continue;
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
    cin>>n;
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b;a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        joint[a][b] = true;
        joint[b][a] = true;
        edges.push_back({a, b});
    }
    int mi =INT_MAX, aa, bb, cc, dd;
    for (int k = 0; k < n-1; ++k) {
        a = edges[k].first; b = edges[k].second;
        joint[a][b] = joint[b][a] = false;//cout<<"a: "<<a<<" b: "<<b<<endl;
        fill_n(vis, n, false);fill_n(vis2, n, false);disjoint.clear();
        for (int i = 0; i < n; ++i) {
            if(!vis[i]){
                //cout<<"i: "<<i<<endl;
                md = 0;
                d = 0;
                dfs(i);
                if(md==0)
                    ind = i;
                md = 0;
                d = 0;
                dfs2(ind);
                for (int i = 0; i < md/2+md%2; ++i) {
                    ind = par[ind];
                }
                disjoint.push_back(ind);
                //cout<<"ind: "<<ind<<endl;
            }
        }
        adj[disjoint[0]].push_back(disjoint[1]);
        adj[disjoint[1]].push_back(disjoint[0]);
        joint[disjoint[0]][disjoint[1]]=true;
        joint[disjoint[1]][disjoint[0]]=true;
        fill_n(vis, n, false);fill_n(vis2, n, false);
        md = 0;
        d = 0;
        dfs(0);
        md = 0;
        d = 0;
        dfs2(ind);
        if(md<mi){
            mi = md;
            aa = a;
            bb = b;
            cc = disjoint[0];
            dd = disjoint[1];
        }
        mi = min(mi, md);
        joint[disjoint[0]][disjoint[1]]=false;
        joint[disjoint[1]][disjoint[0]]=false;
        joint[a][b] = joint[b][a] = true;
    }
    cout<<mi<<endl;
    cout<<aa+1<<" "<<bb+1<<endl;
    cout<<cc+1<<" "<<dd+1<<endl;
    
    return 0;
}

