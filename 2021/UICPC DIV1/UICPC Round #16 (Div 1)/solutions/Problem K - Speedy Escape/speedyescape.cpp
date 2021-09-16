#include <bits/stdc++.h>
using namespace std;

// Speedy Escape

int n, m, e, exi[103], b, p;
vector<pair<int, int>> adj[103];

bool vis[103], reach = 0;

void dfs(int u){
    vis[u] = 1;
    if(u == p)
        return;
    if(exi[u])
        reach = 1;
    for(pair<int, int> v : adj[u])
        if(!vis[v.first])
            dfs(v.first);
}

const double inf = LLONG_MAX;
double police[103], bro[103];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> dij;

int main(){
    cin >> n >> m >> e;
    int u, v, l;
    while(m--)
        cin >> u >> v >> l, u--, v--, adj[u].push_back({v, l}), adj[v].push_back({u, l});
    while(e--)
        cin >> u, exi[u-1] = 1;
    cin >> b >> p, b--, p--;
    dfs(b);
    if(!reach){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    fill_n(police, n, inf);
    police[p] = 0;
    dij.push({0, p});
    while(!dij.empty()){
        double w = dij.top().first;
        int u = dij.top().second;
        dij.pop();
        if(police[u] < w)
            continue;
        for(auto p : adj[u]){
            int v = p.first;
            double c = double(p.second) / 160;
            if(w + c < police[v])
                police[v] = w + c, dij.push({police[v], v});
        }
    }
    double lo = 0, hi = inf;
    while(fabs(hi - lo) > 1e-9){
        double v = (lo + hi) / 2;
        bool judge = 0;
        fill_n(bro, n, inf);
        bro[b] = 0;
        dij.push({0, b});
        while(!dij.empty()){
            double w = dij.top().first;
            int u = dij.top().second;
            dij.pop();
            if(bro[u] < w)
                continue;
            if(exi[u])
                judge = 1;
            for(auto p : adj[u]){
                int f = p.first;
                double c = double(p.second) / v;
                if(w + c < bro[f] && !(police[f] < w + c || fabs(police[f] - w - c) < 1e-9))
                    bro[f] = w + c, dij.push({bro[f], f});
            }
        }
        if(judge)
            hi = v;
        else
            lo = v;
    }
    cout << fixed << setprecision(10) << lo << endl;
}