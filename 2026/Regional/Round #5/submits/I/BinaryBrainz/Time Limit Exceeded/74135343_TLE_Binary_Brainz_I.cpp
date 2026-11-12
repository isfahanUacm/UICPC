#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vll = vector<long long>;
using vp = vector<pair<ll,ll>>;
using vld = vector<long double>;
using vs = vector<string>;
vector<int> spf(1e6+1),ps;
void spf_gen()
{
    for (int i = 2; i<= 1e6; ++i) {
        if (spf[i] == 0) {
            spf[i]=i;
            ps.push_back(i);
        }
        for (int p:ps) {
            if (p>spf[i]||1LL*i*p>1e6) {
                break;
            }
            spf[i*p]=p;
        }
    }
}
int lg(int m, int p){
    int cnt= 0;
    while(m >= p){
        m/=p;
        cnt++;
    }
    return cnt;
};
ld f(ld mid,ll n, vld p, vll a){
    ld ans=mid;
    for (ll i = n-1; i >=0 ; --i) {
        ans=p[i]*min((ld)a[i],1+ans)+(1-p[i])*(ans+1);
    }
    return ans;
}
void solve()
{
    ll n;
    cin>>n;
    vll a(n); vld p(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>p[i];
    }
    ld low=0, high=1000000000.0;
    for (int i = 0; i < 10000; ++i) {
        ld mid=(high+low)/2.0;
        if(f(mid,n,p,a)>mid)
            low=mid;
        else high=mid;
    }
    cout<<fixed<<setprecision(7)<<(low+high)/2.0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while (t--) {
        solve();
        if(t)cout<<endl;
    }
    return 0;
}