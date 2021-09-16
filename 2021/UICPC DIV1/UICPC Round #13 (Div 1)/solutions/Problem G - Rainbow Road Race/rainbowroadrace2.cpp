#include <bits/stdc++.h>
using namespace std;

// Rainbow Road Race

const int inf = INT_MAX;
const int maxn = 7 * 7 * 7 + 3;

map<char, int> mp{{'R', 0}, {'O', 1}, {'Y', 2},
                {'G', 3}, {'V', 4}, {'B', 5}, {'I', 6}};

int n, m, dis[maxn][128+3];
vector<pair<int, pair<int, int>>> adj[maxn];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> dij;

int main(){
    cin >> n >> m;
    int x, y, w;
    char c;
    while(m--)
        cin >> x >> y >> w >> c, x--, y--, adj[x].push_back({y, {w, mp[c]}}), adj[y].push_back({x, {w, mp[c]}});
    for(int i = 0; i < n; i++)
        for(int mask = 0; mask < 128; mask++)
            dis[i][mask] = inf;
    dis[0][0] = 0;
    dij.push({0, {0, 0}});
    while(!dij.empty()){
        int u = dij.top().second.first, mask = dij.top().second.second, w = dij.top().first;
        dij.pop();
        if(dis[u][mask] < w)
            continue;
        for(pair<int, pair<int, int>> p : adj[u]){
            int v = p.first, c = p.second.first, nmask = mask | (1 << p.second.second);
            if(w + c < dis[v][nmask])
                dis[v][nmask] = w + c, dij.push({w + c, {v, nmask}});
        }
    }
    cout << dis[0][127] << endl;
}