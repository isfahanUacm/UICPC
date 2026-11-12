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
    FastIO
    int n, q;
    cin>>n>>q;
    int a[n+1]={};
    FOR(i,1,n) cin>>a[i];
    while (q--){
        int t;
        cin>>t;
        if (t==1){
            int l, r, x;
            cin>>l>>r>>x;
            FOR(i,l,r) a[i]=a[i]%x;
        } else if(t==2){
            int l, r, x;
            cin>>l>>r>>x;
            FOR(i,l,r) a[i]=max(a[i], x);
        } else{
            int l, r;
            cin>>l>>r;
            int s=0;
            FOR(i,l,r) s+=a[i];
            cout<<s<<"\n";
        }
    }
}