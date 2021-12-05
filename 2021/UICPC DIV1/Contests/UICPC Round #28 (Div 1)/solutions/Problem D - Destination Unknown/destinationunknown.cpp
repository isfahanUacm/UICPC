#include <bits/stdc++.h>
using namespace std;

// Destination Unknown

#define num long long int
#define inf LLONG_MAX

const int maxn = 2003;

int n, m, t, s, g, h;
vector<pair<int, num>> adj[maxn];
set<int> pos;
num dist[maxn][3];

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> t >> s >> g >> h, s--, g--, h--;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        pos.clear();
        int x, y;
        num w;
        while(m--)
            cin >> x >> y >> w, adj[x-1].push_back({y-1, w}), adj[y-1].push_back({x-1, w});
        while(t--)
            cin >> x, pos.insert(x-1);
        priority_queue<pair<num, pair<int, bool>>, vector<pair<num, pair<int, bool>>>, greater<pair<num, pair<int, bool>>>> dij;
        for(int i = 0; i < n; i++)
            dist[i][0] = dist[i][1] = inf;
        dist[s][0] = 0, dij.push({0, {s, 0}});
        while(!dij.empty()){
            int u = dij.top().second.first;
            bool s = dij.top().second.second;
            num p = dij.top().first;
            dij.pop();
            if(dist[u][s] < p)
                continue;
            for(pair<int, num> pp : adj[u]){
                int v = pp.first;
                bool b = s ? 1 : (u == g && v == h) || (u == h && v == g);
                num w = pp.second;
                if(p + w < dist[v][b])
                    dist[v][b] = p + w, dij.push({p + w, {v, b}});
            }
        }
        for(int i : pos)
            if(dist[i][1] != inf && dist[i][1] <= dist[i][0])
                cout << i+1 << " ";
        cout << endl;
    }
}