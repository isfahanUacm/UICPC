#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 1000005;
int main(){
    ll c,n,a;
    cin >> c >> n >> a;
    vector<ll> acc(a+10);
    vector<ll> pos(a+10);
    vector<ll> nxt(a+10);
    set<ll> cach;
    ll ans =0;
    for(ll i=0;i<a;i++){
        cin >> acc[i];
    }
    
    for(ll i=0;i<=a;i++)pos[i]=mx;
	for(ll i=a;i>=0;i--){
		nxt[i]=pos[acc[i]];
		pos[acc[i]] = i;
	}
    
    for(ll i=0;i<a;i++){
        if(cach.find(acc[i])!=cach.end())continue;
        if(cach.size()<c){
            cach.insert(acc[i]);
            ans++;
            continue;
        }
        if(cach.size()==c){
            ll last = 0;
            ll last_pos = 0;
            for(auto it = cach.begin();it!=cach.end();it++){
                if(nxt[pos[*it]]>last){
                    last = nxt[pos[*it]];
                    last_pos = *it;
                }
            }
            cach.erase(last_pos);
            cach.insert(acc[i]);
            ans++;
        }

    }
    
    cout<<ans<<endl;
}