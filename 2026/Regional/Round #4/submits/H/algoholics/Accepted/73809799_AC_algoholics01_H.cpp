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
        set<int> st;
        int a[n+1]={};
        FOR(i,1,n){
            cin>>a[i];
            st.insert(a[i]);
        }
        if (st.size()>2){
            cout<<"2\n";continue;
        }
        if (st.size()==1){
            if (*(st.begin()) == 1) cout<<"0\n";
            else cout<<"1\n";
            continue;
        }
        if ((*st.begin()) != 1){
            cout<<"2\n";continue;
        }
        int l=0, r=0, cnt=0;
        FOR(i,1,n){
            if (a[i]!=1){
                cnt++;
                if (l==0) l=i;
                r=i;
            }
        }
        if (r-l+1==cnt) cout<<"1\n";
        else cout<<"2\n";
    }
}