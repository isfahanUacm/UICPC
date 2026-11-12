#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,aaaa,bbbb) for(int i=aaaa;i<=bbbb;i++)
#define FORR(i,aaaa,bbbb) for(int i=aaaa;i>=bbbb;i--)
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define lg 31
#define mxn 1000200
#define mxa 1000006
const long long inf=LLONG_MAX/5;

bool isntPrime[mxn];
vector<int> primes;
signed main(){
    FOR(i,2,mxn-1){
        if (isntPrime[i]==0){
            primes.push_back(i);
        }
        for (auto p:primes){
            if (i*p>=mxn) break;
            isntPrime[i*p]=1;
            if (i%p==0) break;
        }
    }
    FastIO
    int n;
    cin>>n;
    int i=0;
    while (primes[i]<=n) i++;
    cout<<i;
}