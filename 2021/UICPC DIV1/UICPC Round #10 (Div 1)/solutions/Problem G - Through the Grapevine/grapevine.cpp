#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100003
map<string, int> names;
int n, m, d, s;string u, v;
vector<int> adj[MAX_N];
int spec[MAX_N];
bool heard[MAX_N];
int main()
{
    cin>>n>>m>>d;
    for (int i = 0; i < n; ++i) {
        cin>>u>>spec[i];
        names[u]=i;
    }
    for (int i = 0; i < m; ++i) {
        cin>>u>>v;
        adj[names[u]].push_back(names[v]);
        adj[names[v]].push_back(names[u]);
    }
    cin>>u;s = names[u];
    queue<int> q;
    q.push(s);
    heard[s]=true;
    int res = 0;
    while(!q.empty() && d--){
        int si = q.size();
        while(si--){
            s = q.front();
            q.pop();
            for(auto e: adj[s]){
                if(!heard[e])
                    heard[e]=true, res++;
                if(spec[e]>0){
                    spec[e]--;
                    if(!spec[e])
                        q.push(e);
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}

