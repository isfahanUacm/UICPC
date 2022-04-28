#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
map<string, int> mp;
string langs[103];
pair<int, int> dist[103];
int n, m, c;
string a, b;

int main()
{
    cin>>n>>m;
    mp.clear();adj.resize(n+1);
    langs[0] = "English";mp["English"]=0;
    for (int i = 1; i <= n; ++i) {
        cin>>langs[i];
        mp[langs[i]] = i;
        dist[i] = {INT_MAX, INT_MAX};
    }
    for (int i = 0; i < m; ++i) {
        cin>>a>>b>>c;
        adj[mp[a]].push_back({mp[b], c});
        adj[mp[b]].push_back({mp[a], c});
    }
    dist[0] = {0, 0};
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        c = q.front(); q.pop();
        for(auto p : adj[c]){
            if(dist[c].first+1<dist[p.first].first){
                dist[p.first].first = dist[c].first + 1;
                dist[p.first].second = p.second;
                q.push(p.first);
            }
            else if(dist[c].first+1==dist[p.first].first)
                dist[p.first].second = min(p.second, dist[p.first].second);
        }
    }
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        if(dist[i].first==INT_MAX){
            cout<<"Impossible"<<endl;
            return 0;
        }
        s += dist[i].second;
    }
    cout<<s<<endl;
    return 0;
}

