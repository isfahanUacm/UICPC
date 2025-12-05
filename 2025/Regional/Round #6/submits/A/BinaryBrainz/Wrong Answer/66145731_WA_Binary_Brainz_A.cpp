#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
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
//set<ll>st;
//bool is_prime(ull n)
//{
//    if(st.find(n)!=st.end())
//        return true;
//    return false;
//}
//bool prime(ll n)
//{
//    if(n<=1) return false;
//    for (ll i = 2; i*i <=n ; ++i) {
//        if(n%i==0)return false;
//    }
//    return true;
//}
//void gen()
//{
//    st.insert(2);
//    st.insert(3);
//    st.insert(5);
//    st.insert(7);
//    st.insert(11);
//    st.insert(13);
//    st.insert(17);
//    st.insert(19);
//    for (int i = 20; i < 1e4; ++i) {
//        if(prime(i))
//        {
//            st.insert(i);
//        }
//    }
//}

bool possible(vl& a,ll mid,string tmp, string p){

    for (int i = 0; i < mid; ++i) {
        tmp[a[i]-1]='-';
    }
    erase(tmp,'-');
    ll n=tmp.size();
    ll cnt=0;
    ll s=p.size();
    for (int i = 0; i < n; ++i) {
        if(tmp[i]==p[cnt])
        {
            cnt++;
            if(cnt==s)
                return true;
        }
    }
    return false;

}
void bs(vl& a,ll n,const string& t,const string& p){
    ll low=0,high=n;
    ll ans=-1;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(possible(a,mid,t,p))
        {
            low=mid+1;
            ans=max(mid,ans);
        }
        else
        {
            high=mid-1;
        }
    }
    //cout<<fixed<<setprecision(6)<<ans;
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
    ll n;
    ld xc,yc,xa,ya;
    cin>>n>>xc>>yc>>xa>>ya;
    ld x1 , y1, x2 ,y2;
    vector<ld> b(1e7 , 0.0);
    for (int i = 0; i < n; ++i) {
        cin>>x1>>y1>>x2>>y2;
        y1 += 1e6;
        y2 += 1e6;
        b[y2 + 1]--;
        b[y1]++;
    }
    if(ya >= yc){
        cout << fixed << setprecision(8) << 0.0;
        return;
    }
    vector<ld> c(1e7);
    c[0] = b[0];
    for (int i = 1; i < 1e7; ++i) {
        c[i] = c[i - 1] + b[i];
    }
    ld ans = 0;
    for (int i = ya-1; i <= yc ; ++i) {
        if(c[i + 1e6] == 0){
            ans++;
        }
    }
    cout << fixed << setprecision(8) << ans;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
        if(t)cout<<endl;
    }
    return 0;
}