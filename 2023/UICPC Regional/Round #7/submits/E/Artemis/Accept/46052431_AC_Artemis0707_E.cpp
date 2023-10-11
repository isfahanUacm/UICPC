#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mx = 1e4 + 10;
vector<pair<ll,ll>> adj[mx];

ll dist[mx];
ll n,m;
double x;
map<ll,bool> exi;
vector<ll> w;
int main(){
    cin >> n >> m >> x;
    x  = 1 + x/100;
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
        if(exi.find(c) == exi.end()){
            exi[c] = 1;
            w.push_back(c);
        }

    }
    for(ll i=0;i<mx;i++){
            dist[i] = 1e18;
    }
    dist[1] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push(make_pair(0,1));
        while(!pq.empty()){
            ll u = pq.top().second;
            ll d = pq.top().first;
            pq.pop();
            if(d > dist[u]) continue;
            for(auto v:adj[u]){
                if(dist[v.first] > dist[u] + v.second){
                    dist[v.first] = dist[u] + v.second;
                    pq.push(make_pair(dist[v.first],v.first));
                }
            }
    }
    ll sp = dist[n];
    //cerr<<sp<<endl;
    sort(w.begin(),w.end());
    for(auto v:w){
        //cerr<<v<<' ';
    }
    //cerr<<endl;
    ll l = 0;
    ll h = w.size() - 1;
    ll ans = 0;
    ll c = -1;
    set<pair<ll,ll>> pq1;
    while(1){
        pq1.clear();
        ll mid = (l+h)/2;
        c = w[mid];
        for(ll i=2;i<=n;i++){
            dist[i] = 1e18;
            pq1.insert({dist[i], i});
        }
        dist[1] = 0;
        pq1.insert(make_pair(dist[1],1));
        while(!pq1.empty()){
            pair<ll,ll> t = *pq1.begin();
            ll u = t.second;
            ll d = t.first;
            pq1.erase(pq1.begin());
            for(auto v:adj[u]){
                if(v.second > c) continue;
                //cerr<<"vc "<< v.second<< ' '<<c<<endl;
                //cerr<<dist[v.first]<<' '<< dist[u]<<' '<<v.second<<endl;
                if(dist[v.first] > dist[u] + v.second){
                    pq1.erase(make_pair(dist[v.first],v.first));
                    dist[v.first] = dist[u] + v.second;
                    pq1.insert(make_pair(dist[v.first],v.first));
                }
            }
        }
        //cerr<<c<<" "<<" "<<n<<" "<<dist[n]<<' '<<x * double(sp)<<endl;
        if(dist[n] <= x * double(sp)){
            h = mid;
        }
        else{
            l = mid+1;
        }
        
        //cerr << "l " << l<< " h "<<h<<"mid"<<mid<<endl;
        if(l==h)break;
    }
    cout<<w[l]<<endl;
    return 0;
}