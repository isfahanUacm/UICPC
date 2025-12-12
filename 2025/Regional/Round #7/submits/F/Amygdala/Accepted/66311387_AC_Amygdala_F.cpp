#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define int ll


const int N = 2e5+9;
int ans = 0;
vector<vector<int>> adj(N);
int dist[100];
void dfs(int v, int p, int num){
    for(int u : adj[v]){
        if(dist[u] > dist[v]+1|| dist[u]==-1){
            dist[u] = dist[v]+1;
            dfs(u,v, num);
        }
        else if(u!=p && u == num){
            if(ans == 1)
                ans = dist[v]+1;
            else
                ans = min(ans, dist[v]+1);
        }
    }
}
void solve()
{
    int n, m;    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll  sum = 0;
    for(int i=0; i<n; i++) {
        ans = 1;
        memset(dist,-1,sizeof dist);
        dist[i]=0;
        dfs(i,-1,i);
//        cout << ans << " ";
        sum += (i+1)*ans;
    }
    cout << sum << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
