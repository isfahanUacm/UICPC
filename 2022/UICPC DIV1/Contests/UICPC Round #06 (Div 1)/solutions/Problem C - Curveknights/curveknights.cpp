#include <bits/stdc++.h>
using namespace std;

#define num long long int

num n, m, a[53], u, v, w, indeg[53];
vector<pair<num, num>> adj[53];
bool visited[53];

void dfs(num u){
    visited[u] = true;
    for(auto v: adj[u]){
        if (!visited[v.first])
            dfs(v.first);
        a[u] += v.second * a[v.first];
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        indeg[v]++;
    }
    for (int i = 0; i < n; i++){
        if (!indeg[i])
            dfs(i);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}