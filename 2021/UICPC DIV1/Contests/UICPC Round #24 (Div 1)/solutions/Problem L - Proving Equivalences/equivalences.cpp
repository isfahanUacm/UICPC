#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int t, n, m, a, b, nums=0, scc= 0;
int dnum[20003], dlow[20003];
bool visited[20003];
vector<int> s;
int compo[20003];
vector<pair<int, int>> edges;

void tarjan(int u){
    dnum[u] = dlow[u] = nums++;
    visited[u] = true;
    s.push_back(u);
    for (auto v: adj[u]) {
        if(dnum[v] == -1){
            tarjan(v);
        }
        if(visited[v]){
            dlow[u] = min(dlow[u], dlow[v]);
        }
    }
    if(dnum[u] == dlow[u]){
        int w;
        while(true){
            w = s.back();
            s.pop_back();
            visited[w] = false;
            compo[w] = scc;
            if(u==w)break;
        }
        scc++;
    }
}

int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m;
        adj.clear();
        adj.resize(n);
        edges.clear();
        fill_n(dnum, n, -1);
        fill_n(dlow, n, -1);
        fill_n(visited, n, false);
        fill_n(compo, n, -1);
        scc = nums = 0;
        for (int i = 0; i < m; ++i) {
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            edges.push_back({a-1, b-1});
        }
        for (int i = 0; i < n; ++i) {
            if(dnum[i]==-1){
                tarjan(i);
            }
        }
        if(scc==1){
            cout<<0<<endl;
            continue;
        }
            
//        cout<<"scc: "<<scc<<endl;
        int indeg[scc], outdeg[scc];
        fill_n(indeg, scc, 0);fill_n(outdeg, scc, 0);
        for (int i = 0; i < m; ++i) {
            if(compo[edges[i].first] == compo[edges[i].second])
                continue;
//            cout<<"compo "<<compo[edges[i].first]<<endl;
//            cout<<"compo "<<compo[edges[i].second]<<endl;
            outdeg[compo[edges[i].first]]++;
            indeg[compo[edges[i].second]]++;
        }
        int resout = 0, resin = 0;
        for (int i = 0; i < scc; ++i) {
//            cout<<"scc"<<i<<": "<<indeg[i]<<" "<<outdeg[i]<<endl;
            if(outdeg[i] == 0)
                resout++;
            if(indeg[i] == 0)
                resin++;
        }
        cout<<((resin>=resout)?resin:resout)<<endl;
    }
    return 0;
}

