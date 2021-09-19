#include <bits/stdc++.h>
using namespace std;

int dist[346][1<<7];
vector<pair<int, pair<int, int>>> adj[346];
int n, m, a, b, d;char c;
map<char, int> mp;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int main()
{
    mp['V']=0;mp['O']=1;mp['B']=2;mp['G']=3;mp['Y']=4;mp['I']=5;mp['R']=6;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        cin>>a>>b>>d>>c;a--;b--;
        adj[a].push_back({b, {d, mp[c]}});
        adj[b].push_back({a, {d, mp[c]}});
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 1<<7; ++j)
            dist[i][j]=INT_MAX;
    pq.push({0, {0, 0}}); dist[0][0]=0;
    pair<int, pair<int, int>> pp;
    pair<int, int> p;
    while(!pq.empty()){
        pp = pq.top(); pq.pop();
        p = pp.second;
        if(pp.first>dist[p.first][p.second])
            continue;
        for(auto edge : adj[p.first]){
            if(dist[p.first][p.second]+edge.second.first < dist[edge.first][p.second | (1<<edge.second.second)]){
                dist[edge.first][p.second | (1<<edge.second.second)] = dist[p.first][p.second]+edge.second.first;
                pq.push({dist[edge.first][p.second | (1<<edge.second.second)], {edge.first, p.second | (1<<edge.second.second)}});
            }
        }
    }
    cout<<dist[0][(1<<7)-1]<<endl;
    return 0;
}

