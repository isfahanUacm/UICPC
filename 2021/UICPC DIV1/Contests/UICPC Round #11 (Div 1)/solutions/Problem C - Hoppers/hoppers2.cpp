#include <bits/stdc++.h>
using namespace std;

// Hoppers

int n, m;
vector<int> adj[500003];
int color[500003];

bool colorable = true;

void dfs(int u, int c){
    color[u] = c;
    for(int v : adj[u]){
        if(color[v] == -1)
            dfs(v, 1-c);
        else if(color[v] == c)
            colorable = false;
    }
}

int main(){
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, adj[x-1].push_back(y-1), adj[y-1].push_back(x-1);
    fill_n(color, n, -1);
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(color[i] == -1)
            ans++, dfs(i, 0);
    if(!colorable)
        ans--;
    cout << ans << endl;
}