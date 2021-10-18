#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(10003);
int color[10003];
bool deg[10003];
queue<int> q;
int n, m, a, b;

void coloring(int u){
    q.push(u);
    color[u] = 0;
    while(!q.empty()){
        u = q.front();q.pop();
        for (auto v : adj[u]) {
            if(color[v]==INT_MAX){
                color[v] = 1 - color[u];
                q.push(v);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    fill_n(color, n+1, INT_MAX);
    fill_n(deg, n+1, false);
    for (int i = 0; i < m; ++i) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a] = deg[b] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if(!deg[i]){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if(color[i]==INT_MAX)
            coloring(i);
    }
    for (int i = 1; i <= n; ++i) {
        cout<<((color[i])?"house":"pub")<<((i==n)?"\n":" ");
    }
    return 0;
}

