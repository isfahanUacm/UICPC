#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=2e5+9, INF=1e9+7;
vector <int> adj[N];
int mrk[N], dis[N], par[N], a[N], b[N], ans[N];

void BFS(int root){
    fill(dis, dis+N, INF);
    mrk[root] = 1;
    dis[root] = 0;
    queue <int> q;
    q.push(root);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(!mrk[v]){
                q.push(v);
                dis[v] = dis[u] + 1;
                mrk[v] = 1;
            }
        }
    }
}

int32_t main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        a[i] = u; b[i] = v;
    }

    for (int i = 0 ; i <= n ; i++) ans[i] = INF;

    for(int i=0;i<m;i++) {
        for (int j = 0 ; j <= n ; j++) adj[j].clear();

        for (int j = 0 ; j <= m ; j++) {
            if (j != i) {
                adj[a[j]].push_back(b[j]);
                adj[b[j]].push_back(a[j]);
            }
        }

        for (int j = 0 ; j <= n ; j++) mrk[j] = 0;

        BFS(a[i]);
        /*cout << a[i] << " " << b[i] << endl;
        for (int j = 1 ; j <= n ; j++) cout << dis[j] << " ";
        cout << endl;*/

        ans[a[i]] = min(ans[a[i]], dis[b[i]]+1);
        ans[b[i]] = min(ans[b[i]], dis[b[i]]+1);
    }

    int sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (ans[i] == INF) ans[i] = 1;
        sum += ans[i]*i;
    }
    cout << sum;
    return 0;
}