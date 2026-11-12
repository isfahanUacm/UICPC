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


#pragma GCC optimize("O3")
#pragma GCC target("avx2")
bool isntPrime[mxn];
int lp[mxn];
vector<int> primes;
signed main(){
    FOR(i,2,mxn-1){
        if (isntPrime[i]==0){
            primes.push_back(i);
            lp[i]=i;
        }
        for (auto p:primes){
            if (i*p>=mxn) break;
            isntPrime[i*p]=1;
            lp[i*p]=p;
            if (i%p==0) break;
        }
    }
    FastIO
    unordered_map<int,int> facts;
    int q;
    cin>>q;
    while (q--){
        int t, x;
        cin>>t>>x;
        if (t==2){
            for (auto &[p,n]:facts){
                if (n>100) continue;
                n*=x;
            }
            continue;
        }
        int xcp=x;
        unordered_map<int,int> xfacts;
        while (x!=1){
            xfacts[lp[x]]++;
            x/=lp[x];
        }
        x=xcp;
        if (t==1){
            for (auto [p,n]:xfacts){
                facts[p]+=n;
            }
            continue;
        }
        bool ans=1;
        for (auto [p,n]:xfacts){
            if (facts[p]<n){
                ans=0;
                break;
            }
        }
        cout<<(ans?"Yes\n":"No\n");
    }
}