#include <bits/stdc++.h>
using namespace std;
#define MAX_N 103

int dist[MAX_N][10003];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int n, m, a, b, d;
int req[MAX_N];
vector<pair<int, int>> adj[MAX_N];

int main()
{
    cin>>n;
    int sumR = 0;
    for (int i = 0; i < n; ++i)
        cin>>req[i], sumR+=req[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= sumR; ++j) {
            dist[i][j] = INT_MAX;
        }
    }
    cin>>m;
    for (int i = 0; i < m; ++i) {
        cin>>a>>b>>d;a--;b--;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    dist[0][req[0]] = 0;
    pq.push({0, {0, req[0]}});
    pair<int, pair<int, int>> pp;
    pair<int, int> p;
    while(!pq.empty()){
        pp = pq.top(); pq.pop();
        p = pp.second;
        if(pp.first>dist[p.first][p.second])
            continue;
        for (auto v: adj[p.first]) {
            if(dist[v.first][p.second+req[v.first]] > dist[p.first][p.second] + v.second){
                dist[v.first][p.second+req[v.first]] = dist[p.first][p.second] + v.second;
                pq.push({dist[v.first][p.second+req[v.first]], {v.first, p.second+req[v.first]}});
            }
        }
    }
    int mi = INT_MAX, R = 0;
    for (int i = 0; i <= sumR; ++i) {
        if(dist[n-1][i]<mi){
            mi = dist[n-1][i];
            R = i;
        }
        else if(dist[n-1][i] == mi){
            R = max(R, i);
        }
    }
    if(mi == INT_MAX)
        cout<<"impossible"<<endl;
    else
        cout<<mi<<" "<<R<<endl;
    return 0;
}

