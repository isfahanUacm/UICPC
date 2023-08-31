#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 1000005;
ll acc[mx];
unordered_map<ll,set<ll>> pos;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll c,n,a;
    cin >> c >> n >> a;
    
    set<ll> cach;
    ll ans =0;
    for(ll i=0;i<a;i++){
        cin >> acc[i];
        pos[acc[i]].insert(i);
    }
    
    for(auto e:pos){
        if(e.second.size()>0){
            e.second.erase(e.second.begin());
        }
    }
    
    priority_queue<pair<ll,ll>> ined;
    for(ll i=0;i<a;i++){
        if(cach.find(acc[i])!=cach.end())continue;
        if(cach.size()<c){
            cach.insert(acc[i]);
            ined.push({*pos[acc[i]].begin(),acc[i]});
            pos[acc[i]].erase(pos[acc[i]].begin());
            ans++;

        }
        else if(cach.size()==c){
            ll out = ined.top().second;
            ined.pop();
            cach.erase(out);
            cach.insert(acc[i]);
            ined.push({*pos[acc[i]].begin(),acc[i]});
            pos[acc[i]].erase(pos[acc[i]].begin());
            ans++;
        }

    }
    
    cout<<ans<<endl;
}