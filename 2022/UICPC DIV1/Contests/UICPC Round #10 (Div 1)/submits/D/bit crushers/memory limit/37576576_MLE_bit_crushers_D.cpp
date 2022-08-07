#include <bits/stdc++.h>
using namespace std;
// #define ll long long;

int bfs(vector<vector<int>> adj,int a, int b){

    int n=adj.size();
    vector<bool> done(n,false);
    queue<pair<int,int>> q;

    q.push({a,0});
    done[a]=true;

    while (!q.empty())
    {
        pair<int,int> node=q.front();
        q.pop();
        int x=node.first,y=node.second;
        if (x==b)
        {
            return y;
        }
        
        for (int u:adj[x])
        {
            if (!done[u])
            {
                done[u]=true;
                q.push({u,y+1});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    



    int testcase;
    cin>>testcase;   
    for (int t= 0; t < testcase; t++)
    {
        int n,a,b;
        cin>>n>>a>>b;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n && j-i<=arr[i]; j++)
            {
                if (j-i<=arr[j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
            }
            
        }
        
        int ans=bfs(adj,a-1,b-1);
        cout<<ans<<"\n";


    }
   
    return 0;
    
}