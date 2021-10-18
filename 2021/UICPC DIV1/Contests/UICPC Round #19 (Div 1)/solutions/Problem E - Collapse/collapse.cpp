#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj(100003);
bool visited[100003];
queue<int> q;
int need[100003];
int receive[100003];
int N,s,k,t,v;

int main()
{
    cin>>N;
    fill_n(visited, N+1, false);
    fill_n(receive, N+1, 0);fill_n(need, N+1, 0);
    for (int i = 1; i <= N; ++i) {
        cin>>t>>k;need[i] = t;
        for (int j = 0; j < k; ++j) {
            cin>>s>>v;
            adj[s].push_back({i, v});
            receive[i] += v;
        }
    }
    visited[1] = true; N--;
    for (auto v : adj[1]) {
        q.push(v.first);
        receive[v.first] -= v.second;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])
            continue;
        if(receive[u]<need[u]){
            visited[u]= true; N--;
            for(auto v: adj[u]){
                receive[v.first] -= v.second;
                q.push(v.first);
            }
        }
    }
    cout<<N<<endl;
    return 0;
}

