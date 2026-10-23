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
        int n;
        cin>>n;
        int a[n+1]={};
        FOR(i,1,n) cin>>a[i];
        sort(a+1,a+n+1);
        int ans=0, tmp=1;
        a[0]=-1e8;
        FOR(i,1,n){
            if (a[i]==a[i-1]+1){
                tmp++;
            } else if (a[i]==a[i-1]) continue; 
            else{
                ans=max(ans,tmp);
                tmp=1;
            }
        }
        cout<<n-max(ans,tmp)<<"\n";
    }
}