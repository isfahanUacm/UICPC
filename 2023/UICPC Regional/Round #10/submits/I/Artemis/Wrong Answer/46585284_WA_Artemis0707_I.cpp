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
    ll start = 0,num_cmp = 1, prev =-1;
    sort(time,time+n, cmp);
    for(int i=0;i<n;i++){
        if(time[i].second == -1){
            continue;
        }
        else{
            if(time[i].first + start <= time[i].second){
                start += time[i].first;
            }
            else{
                if( start != time[i].second){
                    num_cmp = max(num_cmp, ll(ceil(time[i].first*1.0 / time[i].second)));
                    //  cerr<< "1 "<< num_cmp <<endl;
                }
                else{
                    num_cmp += ll(ceil(time[i].first*1.0 / time[i].second));
                    //  cerr<< "2 "<< num_cmp <<endl;
                }
               
                start = time[i].second;
            }
            prev = time[i].second;
        }
    }
    cout<<num_cmp<<endl;
    return 0;
}
