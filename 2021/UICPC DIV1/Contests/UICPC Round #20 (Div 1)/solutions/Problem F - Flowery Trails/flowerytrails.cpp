#include <bits/stdc++.h>
using namespace std;

#define MAX_n 10003

int dist[MAX_n];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>>adj(MAX_n);
vector<vector<tuple<int, int, int>>> pred(MAX_n);
map<tuple<int, int, int>, int> mp;

int P, T, p0, p1, l;

int main()
{
    cin>>P>>T;
    fill_n(dist, P, INT_MAX);
    for (int i = 0; i < T; ++i) {
        cin>>p0>>p1>>l;
        adj[p0].push_back({p1, l});
        adj[p1].push_back({p0, l});
        if(mp.find(make_tuple(p0, p1, l)) == mp.end())
            mp[make_tuple(p0, p1, l)] = 0, mp[make_tuple(p1, p0, l)] = 0;
        mp[make_tuple(p0, p1, l)] ++;
        mp[make_tuple(p1, p0, l)] ++;
    }
    dist[0] = 0;
    pq.push({0, 0});
    int d, u; pair<int, int> pp;
    while(!pq.empty()){
        pp = pq.top();pq.pop();
        d = pp.first;
        u = pp.second;
        if(d<dist[u] || u==P-1)
            continue;
        for (auto v : adj[u]) {
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
                pred[v.first].clear();
                pred[v.first].push_back(make_tuple(u, v.first, v.second));
            }
            else if(dist[u] + v.second == dist[v.first]){
                pred[v.first].push_back(make_tuple(u, v.first, v.second));
            }
        }
    }
    int res = 0, curr;set<int> s;set<tuple<int, int, int>> e; 
    queue<int> q;q.push(P-1);
    while(!q.empty()){
        curr = q.front(); q.pop();
        s.clear();
        for (auto p : pred[curr]) {
            e.insert(p);
            s.insert(get<0>(p));
        }
        for(auto a : s)
            q.push(a);
    }
    for(auto a: e){
        res += mp[a]*get<2>(a);
    }
    cout<<res*2<<endl;
    return 0;
}

