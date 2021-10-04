#include <bits/stdc++.h>
using namespace std;

// Pub-lic Good

int n, m;
vector<int> adj[10003];
int color[10003];

void dfs(int u, int c){
    color[u] = c;
    for(int v : adj[u])
        if(color[v] == -1)
            dfs(v, 1-c);
}

int main(){
    int x, y;
    cin >> n >> m;
    while(m--)
        cin >> x >> y, adj[x-1].push_back(y-1), adj[y-1].push_back(x-1);
    for(int i = 0; i < n; i++)
        if(adj[i].empty()){
            cout << "Impossible" << endl;
            return 0;
        }
    fill_n(color, n, -1);
    for(int i = 0; i < n; i++)
        if(color[i] == -1)
            dfs(i, 0);
    for(int i = 0; i < n; i++)
        cout << (color[i] ? "pub " : "house ");
    cout << endl;   
}