#include <bits/stdc++.h>
using namespace std;

// Breaking Bad

int n, m;
set<string> names;
map<string, int> id;
vector<int> adj[100003];
int color[100003];

bool ok = true;

void dfs(int u, int c){
    color[u] = c;
    for(int v : adj[u]){
        if(color[v] == -1)
            dfs(v, 1-c);
        else if(color[v] == c)
            ok = false;
    }
}

int main(){
    cin >> n;
    string x, y;
    for(int i = 0; i < n; i++)
        cin >> x, names.insert(x), id[x] = i;
    cin >> m;
    while(m--)
        cin >> x >> y, adj[id[x]].push_back(id[y]), adj[id[y]].push_back(id[x]);
    fill_n(color, n, -1);
    for(int i = 0; i < n; i++)
        if(color[i] == -1)
            dfs(i, 0);
    if(!ok)
        cout << "impossible" << endl;
    else{
        vector<string> a, b;
        for(string name : names){
            if(color[id[name]])
                a.push_back(name);
            else b.push_back(name);
        }
        for(string name : a)
            cout << name << " ";
        cout << endl;
        for(string name : b)
            cout << name << " ";
        cout << endl;
    }
}