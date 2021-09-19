#include <bits/stdc++.h>
using namespace std;

int e, q, v = 0;
vector<pair<char, int>> adjs[503];
map<string, int> mp;
bool vis[503], vis2[503][2];

void dfs_is(int u){
    vis[u] = 1;
    for(auto x : adjs[u]){
        char c = x.first;
        int v = x.second;
        if(c == 'i' && !vis[v])
            dfs_is(v);
    }
}

void dfs_has(int u, int b){
    vis2[u][b] = 1;
    for(auto x : adjs[u]){
        bool b2 = (x.first == 'h') ? true : b;
        if(!vis2[x.second][b2]){
            dfs_has(x.second, b2);
        }
    }
}

int main(){
    cin >> e >> q;
    string x, r, y;
    for(int i = 0; i < e; i++){
        cin >> x >> r >> y;
        if(mp.find(x) == mp.end())
            mp[x] = v++;
        if(mp.find(y) == mp.end())
            mp[y] = v++;
        if(r == "is-a")
            adjs[mp[x]].push_back({'i', mp[y]});
        else
            adjs[mp[x]].push_back({'h', mp[y]});
    }
    for(int i = 0; i < q; i++){
        cout << "Query " << i + 1 << ": ";
        fill_n(vis, v, 0);
        for(int i = 0; i < v; i++)
            for(int j = 0; j < 2; j++)
                vis2[i][j] = 0;
        cin >> x >> r >> y;
        if(r == "is-a"){
            dfs_is(mp[x]);
            if(vis[mp[y]])
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else{
            dfs_has(mp[x], 0);
            if(vis2[mp[y]][1])
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
}