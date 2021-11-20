#include <bits/stdc++.h>
using namespace std;

// Bumped!

#define num long long int
#define inf LLONG_MAX

const int maxn = 5e4 + 3;
int n, m, f, s, t;
vector<pair<int, int>> adjs[maxn];
vector<int> flights[maxn];
num dis[maxn][2 + 3];
priority_queue<pair<num, pair<int, bool>>, vector<pair<num, pair<int, bool>>>, greater<pair<num, pair<int, bool>>>> pq;

int main(){
    cin >> n >> m >> f >> s >> t;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adjs[x].push_back({w, y});
        adjs[y].push_back({w, x});
    }
    for(int i = 0; i < f; i++){
        int x, y;
        cin >> x >> y;
        flights[x].push_back(y);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            dis[i][j] = inf;
    pq.push({0, {s, 0}});
    dis[s][0] = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        num d = p.first;
        int u = p.second.first;
        bool b = p.second.second;
        if(dis[u][b] < d)
            continue;
        if(u == t){
            cout << dis[t][b] << endl;
            return 0;
        }
        if(!b)
            for(int v : flights[u])
                if(dis[v][!b] > d)
                    dis[v][!b] = d, pq.push({dis[v][!b], {v, !b}});
        for(auto x : adjs[u]) 
            if(dis[x.second][b] > d + x.first)
                dis[x.second][b] = d + x.first, pq.push({dis[x.second][b], {x.second, b}}); 
    }
}