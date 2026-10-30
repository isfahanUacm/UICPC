#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,aaaa,bbbb) for(int i=aaaa;i<=bbbb;i++)
#define FORR(i,aaaa,bbbb) for(int i=aaaa;i>=bbbb;i--)
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define lg 31
#define mxn 1000006
#define mxa 1000006
const long long inf=LLONG_MAX/5;


signed main(){
    FastIO
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<pair<int, int>> a, b;
        FOR(i,1,n){
            int x;
            cin>>x;
            b.push_back({x,i});
        }
        FOR(i,1,n){
            int x;
            cin>>x;
            a.push_back({x,i});
        }
        sort(ALL(a));
        sort(ALL(b));
        reverse(ALL(a));
        int ans[n+1][n+1]={};
        for (auto [v,i]:a){
            for (auto &[u, j]:b){
                if (v==0) break;
                int c=min(v,u);
                u-=c;
                v-=c;
                ans[j][i]=c;
            }
        }
        FOR(i,1,n){
            FOR(j,1,n) cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
        for(auto [x,i]:b){
            cout<<i<<" ";
        }
    }
}