#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 7*1e6;
vector<pair<ll,ll>> ans;
vector <pair<ll,pair<ll,ll> > > edge;
ll p[mx],r[mx],n;
void ms(ll x){
    p[x]=x;
    r[x]=0;
}
ll find(ll x){
    return p[x]==x ? p[x]:p[x]=find(p[x]);
}
void un(ll x, ll y){
    ll xs = find(x);
    ll ys = find(y);
    if(xs==ys)return;
    if(r[xs]>r[ys]){
        p[ys]=p[xs];
    }
    else if(r[ys]>r[xs]){
        p[xs]=ys;
    }
    else{
        p[ys]=xs;
        r[xs]++;
    }
}
bool same_set(ll x,ll y){
    return find(x)==find(y);
}
int main(){
    cin >> n;
    for(ll i=1;i<=n;i++)ms(i);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            ll w;
            cin >> w;
            if(i==j)continue;
            edge.push_back({w,{i,j}});
        }
    }
    sort(edge.begin(),edge.end());
    for(auto e:edge){
        if(!same_set(e.second.first,e.second.second)){
            ans.push_back({e.second.first,e.second.second});
            un(e.second.first,e.second.second);
        }
    }
    for(auto e:ans){
        cout<<e.first<<' '<<e.second<<endl;
    }
    return 0;
}