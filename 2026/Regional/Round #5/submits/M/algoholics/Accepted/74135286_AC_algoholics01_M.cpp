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
    int p, h;
    char a, b;
    cin>>a>>b>>p>>h;
    if (a=='F'&&b=='G' || a=='G'&&b=='W' || a=='W'&&b=='F') p*=2;
    else p/=2;
    if (h<=p) cout<<"Nocaute!";
    else cout<<"Sobraram "<<h-p<<" pontos de vida!";
}