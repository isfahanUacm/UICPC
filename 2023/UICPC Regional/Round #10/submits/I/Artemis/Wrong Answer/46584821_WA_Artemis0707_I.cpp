#include<bits/stdc++.h>
using namespace std;
using ll =long long;

bool cmp( const pair<ll,ll> a, const pair<ll,ll> b){
    return a.second <b.second;
}

int main(){
    ll n;
    cin>>n;
    pair<ll,ll> time[n];
    for(int i=0;i<n;i++){
        cin>>time[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>time[i].second;
    }
    ll start = 0,num_cmp = 1;
    sort(time,time+n, cmp);
    for(int i=0;i<n;i++){
        if(time[i].second == -1){
            continue;
        }
        else{
            if(time[i].first <= time[i].second){
                start += time[i].first;
            }
            else{
                // cerr<<time[i].first / time[i].second<<endl;
                num_cmp = max(num_cmp, ll(ceil(time[i].first*1.0 / time[i].second)));
                start = time[i].second;
            }
        }
    }
    cout<<num_cmp<<endl;
    return 0;
}