#include <bits/stdc++.h>
using namespace std;
#define MAX_N 3003
map<string , int> mp;
vector<vector<int>> adj;
bool vis[MAX_N];
pair<int, int> p;
int t, m;
string s1, s2;
int main()
{
    cin>>t;
    while(t--){
        cin>>m;
        adj.resize(m+1);
        int k = 0;
        for (int i = 0; i < m; ++i) {
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
                mp[s1] = k++;
            if(mp.find(s2)==mp.end())
                mp[s2] = k++;
            adj[mp[s1]].push_back(mp[s2]);
            adj[mp[s2]].push_back(mp[s1]);
        }
        bool flag = false;
        for (int i = 0; i < k; ++i) {
            fill_n(vis, k, false);
            vis[i] = true;
            queue<pair<int, int>> q;
            q.push({i, 0});
            while(!q.empty()){
                p = q.front();q.pop();
                if(p.second==6)
                    continue;
                for(auto v: adj[p.first]){
                    if(!vis[v]){
                        vis[v]=true;
                        q.push({v, p.second+1});
                    }
                }
            }
            int c=0;
            for (int j = 0; j < k; ++j) {
                if(!vis[j])
                    c++;
            }
            if(c*100.0/k > 5){
                cout<<"NO"<<endl;
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        cout<<"YES"<<endl;
    }
    return 0;
}

