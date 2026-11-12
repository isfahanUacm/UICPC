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
    int b, h, l;
    cin>>b>>h>>l;
    long double s=l*l*1.5*sqrtl(3);
    cout<<fixed<<setprecision(10)<<(s)/(b*h);
}