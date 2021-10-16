#include <bits/stdc++.h>
using namespace std;

// Treehouses

int n, e, p, par[1003], ran[1003];
double x[1003], y[1003];
vector<pair<double, pair<int, int>>> edges;

inline double dist(int i, int j){
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

bool umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return false;
    if(ran[i] > ran[j])
        par[j] = i;
    else{
        par[i] = j;
        if(ran[i] == ran[j])
            ran[j]++;
    }
    return true;
}

int main(){
    cin >> n >> e >> p;
    iota(par, par + n, 0);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < e - 1; i++)
        umerge(i, i + 1);
    int i, j;
    while(p--)
        cin >> i >> j, umerge(i-1, j-1);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            edges.push_back({dist(i, j), {i, j}});
    sort(edges.begin(), edges.end());
    double ans = 0.0;
    for(auto e : edges)
        if(umerge(e.second.first, e.second.second))
            ans += e.first;
    cout << fixed << setprecision(10) << ans << endl;
}