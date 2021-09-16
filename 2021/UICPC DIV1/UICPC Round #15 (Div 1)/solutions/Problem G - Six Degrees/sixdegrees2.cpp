#include <bits/stdc++.h>
using namespace std;

// Six Degrees

int n, m;
map<string, int> id;

int gid(string name){
    if(id.find(name) == id.end())
        return id[name] = n++;
    return id[name];
}

vector<int> adj[3003];
int dis[3003], lsp[3003];
queue<int> bfs;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m, n = 0, id.clear();
        for(int i = 0; i < 3003; i++)
            adj[i].clear();
        string x, y;
        while(m--){
            cin >> x >> y;
            int i = gid(x), j = gid(y);
            adj[i].push_back(j), adj[j].push_back(i);
        }
        fill_n(lsp, n, 0);
        for(int i = 0; i < n; i++){
            fill_n(dis, n, INT_MAX);
            dis[i] = 0;
            bfs.push(i);
            while(!bfs.empty()){
                int u = bfs.front();
                bfs.pop();
                for(int v : adj[u])
                    if(dis[v] == INT_MAX)
                        dis[v] = dis[u] + 1, bfs.push(v), lsp[i] = max(lsp[i], dis[v]);
            } 
        }
        int ans = count_if(lsp, lsp + n, [](const int& x){return x >= 7;});
        if(100 * ans <= 5 * n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }
}