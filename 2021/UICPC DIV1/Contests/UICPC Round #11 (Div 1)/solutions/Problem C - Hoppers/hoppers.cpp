#include <bits/stdc++.h>
using namespace std;

const int maxn = 500003;
int n, m, a, b;
bool infect[maxn];
vector<int> adj[maxn];
int cc = 0;
int compo[maxn];
vector<int> elemcomp[maxn];
bool vis[maxn];

void dfs(int u){
    vis[u] = true;
    compo[u] = cc;
    elemcomp[cc].push_back(u);
    for(auto v: adj[u])
        if(!vis[v])
            dfs(v);
}

void dfs2(int u){
    infect[u] = true;
    for (auto v: adj[u]) {
        for(auto vu: adj[v]){
            if(!infect[vu])
                dfs2(vu);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill_n(compo, n, -1);
    for (int i = 0; i < n; ++i) {
        if(!vis[i]){
            dfs(i);
            cc++;
        }
    }
    bool flag;
    for (int i = 0; i < cc; ++i) {
        if(elemcomp[i].size() == 1)
            continue;
        dfs2(elemcomp[i][0]);
        flag = true;
        for (auto v: elemcomp[i]) {
            if(!infect[v]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << cc - 1 << endl;
            return 0;
        }
    }
    cout << cc << endl;
    return 0;
}

