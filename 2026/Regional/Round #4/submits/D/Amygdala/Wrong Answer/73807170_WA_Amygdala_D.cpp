#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n)
#define sint(s) string (s); cin >> (s)
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n'
#define int ll
 #define endl '\n'

void print(int a, int b){
    if (a<b){
        cout << "Alice\n";
    }else if(b<a){
        cout << "Bob\n";
    }
    else{
        cout << "Tie\n";
    }
}

void solve()
{
    int n, m;   cin >> n >> m;
    vector<vector<int>> adj(n+1);
    int a, b, c;    cin >> a >> b >> c;
    for(int i=0; i<m; i++){
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(c);
    vector<int> dist(n+1,-1);
    dist[c] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if((dist[u] == -1 )|| (dist[v]+1 < dist[u])){
                // cout << u << '\n';
                dist[u] = dist[v] +1;
                q.push(u);
            }
        }
    }

    vector<int> dista(n+1,-1);
    int da = 1, db=1;
    if(dist[a] == -1){
        q.push(a);
        dista[a] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int u : adj[v]){
                if(dista[u] == -1 || dista[v]+1 < dista[u]){
                    dista[u] = dista[v] +1;
                    q.push(u);
                }
            }
        }
    }else{
        da = dist[a];
    }
    if(dist[b] == -1){
        if(dista[b] != -1){
            db = dista[b]+1;
        }
    }else{
        db = dist[b];
    }
    // cout << da  << " " << db << " ";
    print(da, db);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}