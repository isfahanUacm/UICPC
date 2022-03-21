#include <bits/stdc++.h>

using namespace std;

int r, k, a, res = 0;
vector<int> adj[10003];
bool house[10003], visited[10003];
set<int> around;

void make_graph(){
    int tmp = 1;
    for (int i = 0; i < r-1; ++i) {
        for (int j = tmp; j < tmp+r+i; ++j) {
            if (i == 0)
                around.insert(j);
            if (j + 1 != tmp+r+i){
                adj[j].push_back(j+1);
                adj[j+1].push_back(j);
            }
            adj[j].push_back(j + r + i);
            adj[j].push_back(j + r + i + 1);
            adj[j + r + i].push_back(j);
            adj[j + r + i + 1].push_back(j);
        }
        tmp += r+i;
        around.insert(tmp-1);
        around.insert(tmp);
    }
    int tmp2 = r * r * r - (r-1) * (r-1) * (r-1);
    for (int i = 0; i < r-1; ++i) {
        for (int j = tmp2; j > tmp2-r-i; --j) {
            if (i == 0)
                around.insert(j);
            if (j - 1 != tmp2-r-i){
                adj[j].push_back(j-1);
                adj[j-1].push_back(j);
            }
            adj[j].push_back(j - r - i);
            adj[j].push_back(j - r - i - 1);
            adj[j - r - i].push_back(j);
            adj[j - r - i - 1].push_back(j);
        }
        tmp2 -= r+i;
        around.insert(tmp2);
        around.insert(tmp2+1);
    }
    for (int j = tmp; j < tmp2; ++j) {
        adj[j].push_back(j+1);
        adj[j+1].push_back(j);
    }
}

void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if (house[v])
            res += 1;
        else if (!visited[v])
            dfs(v);
    }
}

int main()
{
    cin >> r >> k;
    for (int i = 0; i < k; ++i) {
        cin >> a;
        house[a] = true;
    }
    make_graph();
    for(auto s: around){
        if(house[s])
            res += 6 - adj[s].size();
        else if (!visited[s]){
            dfs(s);
        }
    }
    cout << res << endl;
    return 0;
}

