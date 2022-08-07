#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[12],res=0;
        for(ll i=0;i<12;i++) arr[i]=0;
        for(ll i=1;i<=n;i++){
            cin>>x>>y;
            arr[y]=max(arr[y],x);
        }
        bool exits=1;
        for(ll i=1;i<=10;i++){
            if(arr[i]==0){
                exits=0;
                break;
            }
            else res+=arr[i];
        }
        if(!exits) cout<<"MOREPROBLEMS\n";
        else cout<<res<<endl;
    }
    return 0;
}