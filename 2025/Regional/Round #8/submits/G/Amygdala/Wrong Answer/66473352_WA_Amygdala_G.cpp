#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

int t,n;
vector<vector<int>> adj(1000);
pair<int,int> srt[1000];
bool mark[1000];
vector<int> ans;
vector<int> res;

bool dfs(int v, int w){
    if(!mark[v]) {
        t++;
        res.push_back(v);
        mark[v] = 1;
    }else{
        if(w < t)
            return false;
        return true;
    }

    for(int u : adj[v]){
        if(dfs(u,w))
            return true;
    }
    return false;
}

void solve()
{
    cin >> n;
    while(n){
        for(int i=0;i<n; i++)
            adj[i].clear();
        for(int i=1; i<n; i++){
            int u,w;    cin >> u >> w;
            u--;
            adj[i].push_back(u);
            srt[i-1] = {w,i};
        }
        sort(srt,srt+n-1);
        memset(mark,0,sizeof mark);
        mark[0] = 1;
        t = -1;
        ans.clear();
        bool flag = 0;
        for(int i=0; i<n-1; i++){
            if(!mark[srt[i].second]){
                if(!dfs(srt[i].second, srt[i].first)){
                    flag = 1;
                    break;
                }else{
                    for(int j = res.size()-1; j>=0; j--)
                        ans.push_back(res[j]);
                }
                res.clear();
            }
        }
        if(flag){
            cout << "no";
            cin >> n;
            if(n)
                cout << '\n';
            continue;
        }
        cout << "yes\n";
        for(int a : ans)
            cout << a+1 << " ";
        cin >> n;
        if(n)
            cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}