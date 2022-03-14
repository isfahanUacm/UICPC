#include <bits/stdc++.h>
using namespace std;


int n, m, u, v;


int main()
{
    while(cin>>n>>m){
        if(!n && !m)
            break;
        bool vis[m];
        fill_n(vis, m, false);
        vector<pair<int, int>> adj[n];
        vector<int> indeg(n, 0), outdeg(n, 0);
        for (int i = 0; i < m; ++i) {
            cin>>u>>v;
            adj[u].push_back({v, i});
            indeg[v]++;outdeg[u]++;
        }
        int curr = u;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if(outdeg[i]-indeg[i]==1)
                curr = i;
            if(outdeg[i]!=indeg[i])
                sum++;
        }
        if(!(sum==0 || sum==2)){
            cout<<"Impossible"<<endl;
            continue;
        }
        vector<int> path;
        stack<int>st;
        while(!st.empty() || outdeg[curr]){
            if (!outdeg[curr]){
                path.push_back(curr);
                curr = st.top(); st.pop();
                continue;
            }
            else{
                for (auto e : adj[curr]){;
                    if (!vis[e.second]){
                        outdeg[curr]--;
                        vis[e.second] = true;
                        st.push(curr);
                        curr = e.first;
                        break;
                    }
                }
            }
        }
        path.push_back(curr);
        if(path.size()!=m+1){
            cout<<"Impossible"<<endl;
            continue;
        }
        for (int i = m; i >= 0; --i) {
            cout<<path[i]<<((i==0)?"\n":" ");
        }
    }
    return 0;
}
