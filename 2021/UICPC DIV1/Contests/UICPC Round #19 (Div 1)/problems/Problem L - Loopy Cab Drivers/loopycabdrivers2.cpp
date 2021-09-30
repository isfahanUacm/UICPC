#include <bits/stdc++.h>
using namespace std;

// Loopy Cab Drivers

const int maxn = 1e5 + 3;

int n = 0, m;
string names[maxn];
map<string, int> id;

int gid(string s){
    if(id.find(s) != id.end())
        return id[s];
    names[n] = s;
    return id[s] = n++;
}

vector<int> adj[maxn];
int cnt = 1, dfsn[maxn], dfsl[maxn];
bool vis[maxn];
stack<int> scc;
vector<set<string>> sccs;

void dfs(int u){
    dfsn[u] = dfsl[u] = cnt++;
    vis[u] = 1;
    scc.push(u);
    for(int v : adj[u]){
        if(!dfsn[v])
            dfs(v);
        if(vis[v])
            dfsl[u] = min(dfsl[u], dfsl[v]); 
    }
    if(dfsl[u] == dfsn[u]){
        set<string> v;
        while(1){
            int x = scc.top();
            scc.pop();
            v.insert(names[x]);
            vis[x] = 0;
            if(x == u)
                break;
        }
        sccs.push_back(v);
    }   
}

set<string> lines;

int main(){
    cin >> m;
    string x, y;
    while(m--)
        cin >> x >> y, adj[gid(x)].push_back(gid(y));
    for(int i = 0; i < n; i++)
        if(!dfsn[i])
            dfs(i);   
    for(set<string> scc : sccs){
        string line = "";
        for(string u : scc)
            line += u + " ";
        lines.insert(line);
    }
    for(string line : lines)
        if(count(line.begin(), line.end(), ' ') >= 2)
            cout << "okay " << line << endl;
    bool avoid = false;
    for(string line : lines)
        if(count(line.begin(), line.end(), ' ') < 2){
            if(!avoid)
                cout <<"avoid ";
            avoid = true;
            cout << line;
    }
    if(avoid) 
        cout << endl;
}