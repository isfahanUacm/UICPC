#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,aaaa,bbbb) for(int i=aaaa;i<=bbbb;i++)
#define FORR(i,aaaa,bbbb) for(int i=aaaa;i>=bbbb;i--)
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define lg 31
#define mxn 100005
#define mxa 1000006
const long long inf=LLONG_MAX/5;


signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n, k;
        cin>>n>>k;
        int a[n+1]={};
        FOR(i,1,n) cin>>a[i];
        if (n>=(1ll<<k)){
            cout<<"0\n";
            continue;
        }
        int cnt=1;
        FOR(i,1,n) cnt=(cnt*((1ll<<k)-i))%998244353;
        cout<<cnt<<'\n';
        map<int, bool> flg;
        int tmp=0, prev=0;
        flg[a[1]]=1;
        FOR(i,1,n){
            // flg[a[i]^prev]=1;
            int x=0;
            FOR(j,0,n){
                if (flg[j^tmp]==0){
                    x=j;
                    break;
                }
            }
            tmp^=x^a[i+1];
            // cout<<"\n";
            // FOR(j,0,n) cout<<"::: "<<flg[j]<<" ";
            // cout<<"\n";
            cout<<x<<" ";
            flg[tmp^a[i+1]]=1;
            prev=x;
        }
        cout<<"\n";
    }
}