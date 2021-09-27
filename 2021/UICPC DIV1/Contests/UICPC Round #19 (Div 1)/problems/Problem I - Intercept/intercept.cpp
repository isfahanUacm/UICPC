#include <bits/stdc++.h>
using namespace std;

// Intercept

const int maxn = 100003;
#define num long long int
#define inf LLONG_MAX

int n, m, s, d;
map<int, num> adj[maxn], adjr[maxn];
num dist[maxn];

bool vis[maxn];
vector<int> adjd[maxn];

void build(int u){
    vis[u] = true;
    for(pair<int, num> v :adjr[u])
        if(dist[u] == dist[v.first] + v.second){
            adjd[u].push_back(v.first), adjd[v.first].push_back(u);
            if(!vis[v.first]) 
                build(v.first);
        }
}

int cnt = 1, dfsn[maxn], dfsl[maxn];
bool ap[maxn];

void dfs(int u, int p){
    dfsn[u] = dfsl[u] = cnt++;
    for(int v : adjd[u]){
        if(!dfsn[v]){
            dfs(v, u);
            if(dfsl[v] >= dfsn[u])
                ap[u] = true;
        }
        if(v != p)
            dfsl[u] = min(dfsl[u], dfsl[v]);
    }
}

int main(){
    int x, y;
    num w;
    cin >> n >> m;
    while(m--){
        cin >> x >> y >> w;
        if(adj[x].find(y) == adj[x].end() || adj[x][y] > w)
            adj[x][y] = w, adjr[y][x] = w;
    }
    cin >> s >> d;
    priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> dij;
    fill_n(dist, n, inf);
    dist[s] = 0, dij.push({0, s});
    while(!dij.empty()){
        num p = dij.top().first;
        int u = dij.top().second;
        dij.pop();
        if(dist[u] < p)
            continue;
        for(pair<int, num> v : adj[u])
            if(p + v.second < dist[v.first])
                dist[v.first] = p + v.second, dij.push({p + v.second, v.first});  
    }
    build(d);
    ap[s] = ap[d] = true;
    dfs(s, -1);
    for(int i = 0; i < n; i++)
        if(ap[i])
            cout << i << " ";
    cout << endl;
}