#include <bits/stdc++.h>
using namespace std;
// #define ll long long;

int bfs(vector<int> reach,int a, int b){

    int n=reach.size();
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
        
        for (int i = 1; i <=reach[x] ; i++)
        {
            int k1=max(0,x-i),k2=min(n-1,x+i);
            if (!done[k1] && reach[k1]>=i)
            {
                done[k1]=true;
                q.push({k1,y+1});
            }
            if (!done[k2] && reach[k2]>=i)
            {
                done[k2]=true;
                q.push({k2,y+1});
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
        int ans=bfs(arr,a-1,b-1);
        cout<<ans<<"\n";


    }
   
    return 0;
    
}