#include <bits/stdc++.h>
using namespace std;
multimap<int,int> m[1000000];
vector<int> adj[100000];
map<int , int> vp;
bool mark[100000];
int maxQ;
bool dfs(int v, int pos){
    mark[v] = 1;
    for(auto u : adj[v]){
        if(!mark[u]){
            pair<int, int> p;
            p.first = min(u,v)*10 + max(u,v);
            maxQ = max(maxQ, vp.find(min(u,v)*10 + max(u,v))->second);
            if(pos == u)
                return true;
            if(dfs(u,pos))
                return true;
        }
    }
    return false;
}

void solve()
{
    int t; cin >> t;
    for(int i = 0 ; i < t; i ++)
    {
        int n,m;cin>>n>>m;
        for(int j = 1 ; j <= m;j++)
        {
            int num;cin>>num;
            int u,v; cin >> u >> v;
            if(num==1)
            {

                adj[u].push_back(v);
                adj[v].push_back(u);
                int ind = min(u,v)*10 + max(u,v);
                vp[ind]=j;
            }else
            {
                memset(mark,0,sizeof mark);
                maxQ = 0;
                if(dfs(u,v))
                    cout << maxQ << '\n';
                else
                    cout << -1 << '\n';
            }

        }
    }

}

int main()
{
    solve();
}
