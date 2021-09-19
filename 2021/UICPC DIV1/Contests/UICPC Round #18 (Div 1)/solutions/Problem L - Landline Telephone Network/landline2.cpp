#include <bits/stdc++.h>
using namespace std;

// Landline Telephone Network

const int maxn = 1e3 + 5;

int n, m, p, cnt;
bool taken[maxn], ins[maxn];
vector<pair<int, int>> adj[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void prim(int u){
    cnt--;
    taken[u] = true;
    for(auto v : adj[u])
        if(!taken[v.first] && !ins[v.first])
            pq.push({v.second, v.first});
}

int main(){
    cin >> n >> m >> p;
    cnt = n - p;
    int x, y, w;
    for(int i = 0; i < p; i++)
        cin >> x, ins[x - 1] = true;
    while(m--)
        cin >> x >> y >> w, x--, y--, adj[x].push_back({y, w}), adj[y].push_back({x, w});
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n == 2 && p == 2){
        if(adj[0].empty())
            cout << "impossible" << endl;
        else cout << adj[0][0].second << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        if(!ins[i]){
            prim(i);
            break;
        }
    int ans = 0;
    while(!pq.empty()){
        int u = pq.top().second, w = pq.top().first;
        pq.pop();
        if(taken[u])
            continue;
        ans += w;
        prim(u);
    }
    if(cnt){
        cout << "impossible" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        if(ins[i]){
            int w = INT_MAX;
            for(auto u : adj[i])
                if(!ins[u.first])
                    w = min(w, u.second);
            if(w == INT_MAX){
                cout << "impossible" << endl;
                return 0;
            }
            ans += w;           
        }
    cout << ans << endl;
}