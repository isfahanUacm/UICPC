#include <bits/stdc++.h>
using namespace std;

vector<int> s;
vector<vector<int>> adj;
vector<pair<int, int>> roads;
int dnum[53], dlow[53];
bool visited[53];
int n, m, a, b, nums=0, scc=0;
bool ans = false;
bool dele = false; int uu, vv;

void tarjanscc(int u){
    dnum[u]= dlow[u] = nums++;
    visited[u] = true;
    s.push_back(u);
    vector<int> ad = adj[u];
    if(dele && u == vv)
        ad.push_back(uu);
    for (auto v : ad) {
        if(dele && u == uu && v == vv){
            continue;
        }
        if(dnum[v] == -1){
            tarjanscc(v);
        }
        if(visited[v]){
            dlow[u] = min(dlow[u], dlow[v]);
        }
    }
    
    if(dnum[u] == dlow[u]){
        scc++;
        int w;
        while(true){
            w=s.back();s.pop_back();visited[w]=false;
            if(w==u)
                break;
        }
    }
}

int main()
{
    int t=0;
    while(cin>>m>>n){
        t++;
        fill_n(dnum, m, -1);
        fill_n(dlow, m, -1);
        fill_n(visited, m, false);
        roads.clear();
        ans = false;
        adj.clear();
        adj.resize(m);
        for (int i = 0; i < n; ++i) {
            cin>>a>>b;
            adj[a].push_back(b);
            roads.push_back({a, b});
        }
        scc = nums = 0;
        bool rep = false;
        for (int i = 0; i < m; ++i) {
            if(dnum[i]==-1){
                if(rep){
                    ans = false;
                    break;
                }
                rep = true;
                tarjanscc(i);
                if(scc==1)
                    ans = true;
            }
        }
        cout<<"Case "<<t<<": ";
        if(ans){
            cout<<"valid"<<endl;
            continue;
        }
        dele = true;
        for (int k = 0; k < n; ++k) {
            fill_n(dnum, m, -1);
            fill_n(dlow, m, -1);
            fill_n(visited, m, false);
            scc = nums = 0;
            rep = false;ans = false;
            uu = roads[k].first; vv = roads[k].second;
            for (int i = 0; i < m; ++i) {
                if(dnum[i]==-1){
                    if(rep){
                        ans = false;
                        break;
                    }
                    rep = true;
                    tarjanscc(i);
                    if(scc==1)
                        ans = true;
                }
            }
            if(ans){
                cout<<uu<<" "<<vv<<endl;
                break;
            }
        }
        if(ans)
            continue;
        cout<<"invalid"<<endl;
    }
    return 0;
}

