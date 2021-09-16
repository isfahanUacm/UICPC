#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int T, n, m, a, b;


int topol(vector<int> indeg, vector<int> ps, int curr){
    int res = 0;
    queue<int> q[2];
    for (int i = 1; i <= n; ++i) {
        if(!indeg[i]){
            q[ps[i]].push(i);
        }
    }
    while(!(q[0].empty() && q[1].empty())){
        while(!q[curr].empty()){
            int u = q[curr].front();
            q[curr].pop();
            for (auto v:adj[u]) {
                indeg[v]--;
                if(!indeg[v])
                    q[ps[v]].push(v);
            }
        }
        curr = 1-curr;
        res++;
    }
    return res-1;
}

int main()
{
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> pos(n+1, 0);
        vector<int> indegree(n+1, 0);
        adj.clear();
        adj.resize(n+1);
        for (int i = 1; i <= n; ++i)
            cin>>pos[i], pos[i]--;
        for (int i = 0; i < m; ++i) {
            cin>>a>>b;
            adj[a].push_back(b);
            indegree[b]++;
        }
        cout<<min(topol(indegree, pos, 0), topol(indegree, pos, 1))<<endl;
    }
    return 0;
}

