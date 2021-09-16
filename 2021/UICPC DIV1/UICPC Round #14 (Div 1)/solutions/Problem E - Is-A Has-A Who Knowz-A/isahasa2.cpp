#include <bits/stdc++.h>
using namespace std;

// Is-A? Has-A? Who Knowz-A?

int n, m, cnt = 0;
map<string, int> id;

int gid(string s){
    if(id.find(s) != id.end())
        return id[s];
    return id[s] = cnt++;
}

vector<int> adji[503];
vector<int> adjh[503];

bool vis[503];

void dfs(int u){
    vis[u] = 1;
    for(int v : adji[u])
        if(!vis[v])
            dfs(v);
}

bool vis2[503][3];

void dfs2(int u, bool b){
    vis2[u][b] = 1;
    for(int v : adji[u])
        if(!vis2[v][b])
            dfs2(v, b);
    for(int v : adjh[u])
        if(!vis2[v][1])
            dfs2(v, 1);
}


int main(){
    cin >> n >> m;
    string x, o, y;
    while(n--){
        cin >> x >> o >> y;
        if(o == "is-a")
            adji[gid(x)].push_back(gid(y));
        else
            adjh[gid(x)].push_back(gid(y));
    }
    for(int t = 1; t <= m; t++){
        cin >> x >> o >> y;
        bool ans;
        if(o == "is-a"){
            fill_n(vis, 503, false);
            dfs(gid(x));
            ans = vis[gid(y)];
        }
        else{
            for(int i = 0; i < 503; i++)
                for(int j = 0; j < 3; j++)
                    vis2[i][j] = false;
            dfs2(gid(x), 0);
            ans = vis2[gid(y)][1];
        }
        cout << "Query " << t << ": " << (ans ? "true" : "false") << endl;
    }
}