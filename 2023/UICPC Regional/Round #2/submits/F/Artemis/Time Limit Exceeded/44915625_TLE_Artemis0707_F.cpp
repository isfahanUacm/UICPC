#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;
const ll mx = 1e3+10;
const ll mxc = 105;
ll n,m;
vector<pair<ll,ll>> adj[mx];
ll dist[mx][mxc];
ll p[mx];


ll dijkstra(ll c, ll s,ll t){
    set<pair<ll,pair<ll,ll>>> q;
    q.insert({0,{0,s}});
    dist[s][0]=0;
  
    while(!q.empty()){
        ll u = q.begin()->second.second;
        ll fuel = q.begin()->second.first;
        if(u==t){
            return dist[u][fuel];
        }
        q.erase(q.begin());
        for(ll i=fuel+1;i<=c;i++){
            dist[u][i] = min(dist[u][i], dist[u][fuel] + (i - fuel) * p[u]);
            q.insert({dist[u][i],{i,u}});
            //cerr<<u<<" "<<i<<" "<<dist[u][i]<<endl;
        }
        for(auto v:adj[u]){
            if(fuel >= v.second){
               // cerr<<v.first<<" "<<fuel-v.second<<" "<<dist[v.first][fuel-v.second]<<endl;
                if(dist[v.first][fuel-v.second] > dist[u][fuel]){
                    q.erase({dist[v.first][fuel-v.second],{fuel-v.second,v.first}});
                    dist[v.first][fuel-v.second] = dist[u][fuel];
                    q.insert({dist[v.first][fuel-v.second],{fuel-v.second,v.first}});
                }
                
            }
            
        }
    }
    return inf;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(ll i=0;i<mx;i++){
		for(ll j=0;j<mxc;j++)
            dist[i][j]=inf;
	}
    for(ll i=0;i<n;i++)
        cin >> p[i];
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    ll q;
    cin >> q;
    while(q--){
        ll c, s,t;
        cin >> c >>  s >> t;
        for(ll i=0;i<n;i++){
		    for(ll j=0;j<=c;j++)
                dist[i][j]=inf;
	    }

       ll ans =  dijkstra(c,s,t);
       if (ans == inf)
            cout << "impossible\n";
        else
            cout << ans << "\n";
        

    }
}
