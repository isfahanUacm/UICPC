#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vl = vector<long long>;
struct pack{
    ld x1,y1,x2,y2;
};
using vp = vector<pack>;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ld eps = 1e-7;

ll up(ll q,vl& a){//greater that is smaller or equal to q
    ll low=0,high=a.size()-1;
    ll ans=-1;
    ll mid=(low+high)/2;
    while(low<=high)
    {
        if(a[mid]<=q){
            low=mid+1;
            ans=max(mid,ans);
            mid=(low+high)/2;
        }
        else if(a[mid]>q)
        {
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    return ans;
}
ll lo(ll q,vl& a){//smallest that is bigger or equal(lower_bound)
    ll low=0,high=a.size()-1;
    ll ans=a.size();
    ll mid=(low+high)/2;
    while(low<=high)
    {
        if(a[mid]<q){
            low=mid+1;
            mid=(low+high)/2;
        }
        else if(a[mid]>=q)
        {
            high=mid-1;
            ans=min(mid,ans);
            mid=(low+high)/2;
        }
    }
    return ans;
}
set<ll>st;
bool is_prime(ll n)
{
    if(st.find(n)!=st.end())
        return true;
    return false;
}
bool prime(ll n)
{
    if(n<=1) return false;
    for (ll i = 2; i*i <=n ; ++i) {
        if(n%i==0)return false;
    }
    return true;
}
void gen()
{
    st.insert(2);
    st.insert(3);
    st.insert(5);
    st.insert(7);
    st.insert(11);
    st.insert(13);
    st.insert(17);
    st.insert(19);
    for (int i = 20; i < 1e6; ++i) {
        if(prime(i))
        {
            st.insert(i);
        }
    }
}

bool possible(ll n,ld x,ld y,ll m){
    return m/x + m/y>=n-1;
}
void bs(ll n,ll x, ll y){
    ll low=0,high=inf;
    ll ans=inf;
    while(low<=high)
    {
        ll mid=low+(high-low)/2;
        if(!possible(n,x,y,mid-min(x,y)))
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
            ans=min(mid,ans);
        }
    }
    //cout<<fixed<<setprecision(6)<<ans;123
    cout<<ans;
}
ld f(vp& a, ld m)
{
    ld ans=-1;
    for (int i = 0; i < a.size(); ++i) {
        // ans=max(ans,fabs(a[i].x-m)/a[i].v);
    }
    return ans;
}
void ts(vp& a)
{
    ld lo=1e-9; ld hi=1e9;//lo and hi are input parameters
    while(hi-lo>eps)
    {
        ld m1=lo+(hi-lo)/3;
        ld m2=hi-(hi-lo)/3;
        ld f1= f(a,m1), f2= f(a,m2);
        if(f1>=f2)
        {
            lo=m1;
        }
        else
        {
            hi=m2;
        }
    }
    cout<<fixed<<setprecision(6)<<f(a,lo);
}

void solve()
{
    ll m;
    cin >> m;

    auto lg = [](ll m, ll p){
        ll cnt= 0;
        while(m >= p){
            m/=p;
            cnt++;
        }
        return cnt;
    };

    auto chiz = [&](ll m, ll p){

        ll res = lg(m,p);
        ll tmp = lg(res,2);

        return tmp + 1;

    };

    ll ans = 0;

    for(auto &itr: st){
        if(itr > m){
            break;
        }
//        cout << itr <<' '<< chiz(m,itr) <<'\n';

        ans += chiz(m,itr);
    }

    cout << ans + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    gen();
    cin >> t;
    while (t--) {
        solve();
        if(t)cout<<endl;
    }
    return 0;
}