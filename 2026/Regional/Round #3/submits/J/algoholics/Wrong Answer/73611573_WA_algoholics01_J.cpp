#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,aaaa,bbbb) for(int i=aaaa;i<=bbbb;i++)
#define FORR(i,aaaa,bbbb) for(int i=aaaa;i>=bbbb;i--)
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define lg 31
#define mxn 300005
#define mxa 1000006
const long long inf=LLONG_MAX/5;


signed main(){
    int tc;
    cin>>tc;
    while (tc--){
        bool res[60]={};
        vector<int> v[2];
        int indx;
        FOR(i,0,59){
            cout<<"? "<<(1ll<<i)<<" "<<(1ll<<i)<<endl;
            cin>>res[i];
            if (res[i]==1) indx=i;
        }
        v[0].push_back(indx);
        FOR(i,0,59){
            if (i==indx) continue;
            if (res[i]==0) continue;
            cout<<"? "<<((1ll<<indx) | ((1ll<<i)))<<" "<<((1ll<<indx) | ((1ll<<i)))<<endl;
            int x;cin>>x;
            if (x==1) v[0].push_back(i);
            else v[1].push_back(x);
        }
        vector<int> v1;
        FOR(i,0,59){
            if (res[i]==0){
                cout<<"? "<<((1ll<<indx) | ((1ll<<i)))<<" "<<((1ll<<indx) | ((1ll<<i)))<<endl;
                int x;cin>>x;
                if (x==1) v1.push_back(i);
            }
        }
        int a=0, b=0;
        for (auto i:v1){
            a+=1ll<<i;
            b+=1ll<<i;
        }
        for (auto i:v[0]){
            a+=1ll<<i;
        }
        for (auto i:v[1]){
            b+=1ll<<i;
        }
        cout<<"! "<<min(a, b)<<" "<<max(a, b)<<endl;
    }
}