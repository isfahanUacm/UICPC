#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 1e5+10;
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
    
    for(ll i=0;i<n;i++){
        if(pos[i].size()>0){
            pos[i].erase(pos[i].begin());
            pos[i].insert(a+10);
        }
    }
    
    set<pair<ll,ll>> ined;
    for(ll i=0;i<a;i++){
        if(cach.find(acc[i])!=cach.end()){
            //cerr<<*pos[acc[i]].begin()<< " "<<acc[i]<<' ';
            ined.erase({*pos[acc[i]].begin(),acc[i]});
            if(*pos[acc[i]].begin() != a+10)
                pos[acc[i]].erase(pos[acc[i]].begin());
            //cerr<<*pos[acc[i]].begin()<<endl;
            ined.insert({*pos[acc[i]].begin(),acc[i]});
            continue;

        }
        if(cach.size()<c){
            cach.insert(acc[i]);
            ined.insert({*pos[acc[i]].begin(),acc[i]});
            if(*pos[acc[i]].begin() != a+10)
                pos[acc[i]].erase(pos[acc[i]].begin());
            ans++;

        }
        else if(cach.size()==c){
            ll out = ined.rbegin()->second;
            ined.erase(*ined.rbegin());
            cach.erase(out);
            cach.insert(acc[i]);
            ined.insert({*pos[acc[i]].begin(),acc[i]});
            if(*pos[acc[i]].begin() != a+10)
                pos[acc[i]].erase(pos[acc[i]].begin());
            ans++;
        }

    }
    
    cout<<ans<<endl;
}