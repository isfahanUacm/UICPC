#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,aaaa,bbbb) for(int i=aaaa;i<=bbbb;i++)
#define FORR(i,aaaa,bbbb) for(int i=aaaa;i>=bbbb;i--)
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define lg 31
#define mxn 200005
#define mxa 1000006
const long long inf=LLONG_MAX/5;


signed main(){
    FastIO
    int n;
    cin>>n;
    if (n%2==0) cout<<n*(n+2)/4;
    else cout<<(n+1)*(n+1)/4;
}