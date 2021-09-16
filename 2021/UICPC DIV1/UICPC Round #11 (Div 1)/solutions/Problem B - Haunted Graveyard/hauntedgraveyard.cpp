#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
int a, b, aa, bb, w, h, g, e, t;
int dist[903];
bool vis[903], gravies[903], hole[903], targs[903];
int dirw[4] = {0, -1, 0, 1};
int dirh[4] = {-1, 0, 1, 0};

bool dfs(int u){
    vis[u] = true;
    for (auto v: adj[u]){
        if(targs[v.first])
            return true;
        if(!vis[v.first] && dfs(v.first))
            return true;
    }
    return false;
}

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<h && j<w;
}

int main()
{
    while(cin>>w>>h){
        if(!w && !h)
            break;
        fill_n(dist, w*h, INT_MAX);fill_n(vis, w*h, false);fill_n(gravies, w*h, false);fill_n(hole, w*h, false);
        fill_n(targs, w*h, false);
        adj.clear();adj.resize(w*h);
        cin>>g;
        for (int i = 0; i < g; ++i) {
            cin>>a>>b;
            gravies[b*w+a]=true;
        }
        cin>>e;
        for (int i = 0; i < e; ++i) {
            cin>>a>>b>>aa>>bb>>t;
            hole[b*w+a]=true;
            adj[b*w+a].push_back({bb*w+aa, t});
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if(hole[i*w+j]||gravies[i*w+j]||(i==h-1&&j==w-1))
                    continue;
                for (int k = 0; k < 4; ++k) {
                    if(inrange(i+dirh[k], j+dirw[k]) && !gravies[(i+dirh[k])*w+j+dirw[k]]){
                        adj[i*w+j].push_back({(i+dirh[k])*w+j+dirw[k], 1});
                    }
                }
            }
        }
        dist[0] = 0;vis[0]=true;
        for (int i = 0; i < w*h-1; ++i)
            for (int u=0; u<w*h; u++)
                for (auto v : adj[u])
                    if(dist[u]!= INT_MAX && dist[u] + v.second < dist[v.first]){
                        dist[v.first] = dist[u] + v.second;
                        if(vis[u])vis[v.first]=true;
                    }
        bool flag = false;
        for (int u=0; u<w*h; u++){
            for (auto v : adj[u])
                if(dist[u]!= INT_MAX && dist[v.first] > dist[u] + v.second && vis[u]){
                    cout<<"Never"<<endl;
                    flag = true;
                    break;
                }
            if(flag)break;
        }
        if(flag)continue;
        
        cout<<((!vis[w*h-1])?"Impossible":to_string(dist[w*h-1]))<<endl;
    }
    return 0;
}
