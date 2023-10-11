#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 3*1e5 + 10;
ll c,p,x,l;
vector<ll> adj[mx];
ll first_deg[mx];
ll deg[mx];
int main(){
    cin >> c >> p >> x >> l;
    for(ll i=0;i<p;i++){
        ll a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
        first_deg[a]++;
        first_deg[b]++;
    }
    bool ans = 0;
    queue<ll> q;
    q.push(l);
    deg[l] = 0;
    while(!q.empty()){
        ll u = q.front();q.pop();
        if(u == x){
            ans = 1;
            break;
        }
        for (auto v:adj[u]){
            if(deg[v] > 0){
                deg[v]--;
                if(deg[v] <= first_deg[v]/2){
                    deg[v] = 0;
                    q.push(v);
                }
            }
        }
    }
    if(ans) cout << "leave" << endl;
    else cout << "stay" << endl;
}