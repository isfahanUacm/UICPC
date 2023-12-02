#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> adj[100005];
bool visited[100005];
int main(){

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<pair<ll,ll>> places(n+2);
        for(ll i=0;i<n+2;i++){
            cin >> places[i].first >> places[i].second;
            visited[i] = 0;
        }

        pair<ll,ll> g = places[n+1];
        
        for(ll i=0;i<=n+2;i++){
            adj[i].clear();
        }
        for(ll i=0;i<=n+1;i++){
            for(ll j=0;j<=n+1;j++){
                if(i==j) continue;
                ll x = abs(places[i].first-places[j].first);
                ll y = abs(places[i].second-places[j].second);
                if(x+y <= 1000){
                    adj[i].push_back(j);
                }
            }
        }
        queue<ll> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            ll u = q.front();
            q.pop();
            for(ll i=0;i<adj[u].size();i++){
                ll v = adj[u][i];
                if(!visited[v]){
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        if(visited[n+1]){
            cout << "happy" << endl;
        }
        else{
            cout << "sad" << endl;
        }
    }
    return 0;
}