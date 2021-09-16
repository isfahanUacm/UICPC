#include <bits/stdc++.h>
using namespace std;

#define MAX_n 2600

int dist[MAX_n];
vector<vector<pair<int, int>>> adj;
pair<int, int> points[MAX_n];
int pre[MAX_n];
int n, u, w;

int calc(int i, int j){
    return (points[i].first-points[j].first)*(points[i].first-points[j].first) + (points[i].second-points[j].second) * (points[i].second-points[j].second);
}

int main()
{
    cin>>n;
    adj.resize(n+2);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill_n(dist, n+2, INT_MAX);
    fill_n(pre, n+2, -1);
    for (int i = 0; i < n; ++i)
        cin>>points[i].first>>points[i].second;
    cin>>points[n].first>>points[n].second;
    cin>>points[n+1].first>>points[n+1].second;
    for (int i = 0; i < n+1; ++i) {
        for (int j = i+1; j < n+2; ++j) {
            w = calc(i, j);
            adj[i].push_back({j, w});
            adj[j].push_back({i, w});
        }
    }
    dist[n] = 0;
    pq.push({0, n});
    pair<int, int> pp;
    while(!pq.empty()){
        pp = pq.top(); pq.pop();
        w = pp.first;
        u = pp.second;
        if(w>dist[u])
            continue;
        for(auto v: adj[u]){
            if(dist[u]+v.second<dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pre[v.first] = u;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    vector<int> path;
    int curr = n+1;
    while(curr!=-1){
        path.push_back(curr);
        curr = pre[curr];
    }
    if(path.size()==2){
        cout<<"-"<<endl;
    }
    else{
        for (int i = path.size()-2; i > 0; --i) {
            cout<<path[i]<<endl;
        }
    }
    return 0;
}

