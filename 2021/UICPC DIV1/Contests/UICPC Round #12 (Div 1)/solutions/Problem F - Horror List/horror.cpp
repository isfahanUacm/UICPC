#include <bits/stdc++.h>
using namespace std;

int n, h, l, a, b;
vector<vector<int>> adj;
int dist[1003];

int main()
{
    cin>>n>>h>>l;
    fill_n(dist, n, INT_MAX);
    adj.resize(n);
    queue<int> q;
    for (int i = 0; i < h; ++i) {
        cin>>a;
        dist[a] = 0;
        q.push(a);
    }
    for (int i = 0; i < l; ++i) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while(!q.empty()){
        a = q.front(); q.pop();
        for (auto v: adj[a]) {
            if(dist[a]+1<dist[v]){
                dist[v] = dist[a] + 1;
                q.push(v);
            }
        }
    }
    int mhi = -1, ind = -1;
    for (int i = 0; i < n; ++i) {
        if(dist[i]>mhi){
            mhi = dist[i];
            ind = i;
        }
    }
    cout<<ind<<endl;
    return 0;
}

