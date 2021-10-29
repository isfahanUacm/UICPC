#include <bits/stdc++.h>
using namespace std;

// Backpack Buddies

const int maxn = 1e5 + 3;
const int inf = INT_MAX;

int n, m;
vector<pair<int, int>> adj[maxn];
int dis1[maxn], dis2[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij1, dij2;
map<int, int> sources;
set<int> frontier;

int main(){
    int x, y, w;
    cin >> n >> m;
    while(m--)
        cin >> x >> y >> w, adj[x].push_back({y, w}), adj[y].push_back({x, w});
    fill_n(dis1, n, inf);
    dis1[0] = 0, dij1.push({0, 0});
    while(!dij1.empty()){
        int u = dij1.top().second, w = dij1.top().first;
        dij1.pop();
        if(dis1[u] < w)
            continue;
        for(pair<int, int> v : adj[u])
            if(w + v.second < dis1[v.first])
                dis1[v.first] = w + v.second, dij1.push({w + v.second, v.first});
    }
    w = dis1[n-1];
    int ans1 = w ? ((w % 12) ? ((w / 12) * 12 + w) : ((w / 12 - 1) * 12 + w)) : 0;
    int level = 0;
    sources[0] = 0;
    fill_n(dis2, n, inf);
    while(1){
        for(pair<int, int> s : sources)
            dis2[s.first] = s.second, dij2.push({s.second, s.first});
        frontier.clear();
        while(!dij2.empty()){
            int u = dij2.top().second, w = dij2.top().first;
            dij2.pop();
            if(dis2[u] < w)
                continue;
            frontier.insert(u);
            for(pair<int, int> v : adj[u])
                if(w + v.second <= 12 && w + v.second < dis2[v.first])
                    dis2[v.first] = w + v.second, dij2.push({w + v.second, v.first});
        }
        if(frontier.find(n-1) != frontier.end())
            break;
        sources.clear();
        for(int u : frontier)
            for(pair<int, int> v : adj[u])
                if(dis2[v.first] == inf){
                    if(sources.find(v.first) != sources.end())
                        sources[v.first] = min(sources[v.first], v.second);
                    else 
                        sources[v.first] = v.second;
                }
        level++;
    }
    int ans2 = 24 * level + dis2[n-1];
    cout << ans2 - ans1 << endl;
}