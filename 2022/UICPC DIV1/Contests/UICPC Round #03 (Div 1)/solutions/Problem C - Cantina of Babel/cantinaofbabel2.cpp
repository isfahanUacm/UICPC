#include <bits/stdc++.h>
using namespace std;

// Cantina of Babel

int n;
vector<int> adj[103];
string l[103];
set<string> lu[103];

int cnt = 1, ans;
int vis[103], dfsn[103], dfsl[103];
stack<int> scc;

void dfs(int u){
    vis[u] = 1;
    dfsn[u] = dfsl[u] = cnt++;
    scc.push(u);
    for(int v : adj[u]){
        if(!dfsn[v])
            dfs(v);
        if(vis[v])
            dfsl[u] = min(dfsl[u], dfsl[v]);
    }
    if(dfsl[u] == dfsn[u]){
        int curr = 0;
        while(1){
            int v = scc.top();
            scc.pop();
            curr++;
            vis[v] = 0;
            if(v == u)
                break;
        }
        ans = max(ans, curr);
    }
}

int main(){
    cin >> n;
    cin.ignore();
    string line, x;
    for(int i = 0; i < n; i++){
        getline(cin, line);
        stringstream ss(line);
        ss >> x >> l[i];
        lu[i].insert(l[i]);
        while(ss >> x)
            lu[i].insert(x);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(lu[j].find(l[i]) != lu[j].end())
                adj[i].push_back(j);
    ans = 1;
    for(int i = 0; i < n; i++)
        if(!dfsn[i])
            dfs(i);
    cout << n - ans << endl;      
}