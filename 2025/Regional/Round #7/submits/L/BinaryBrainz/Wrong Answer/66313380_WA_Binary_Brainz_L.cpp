#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vl = vector<long long>;
struct pack{
    ll t,z,y,b=0;
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
//bool is_prime(ll n)
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

bool possible(ll n, vl& a, ll mid) {

}
ull dis(ull mid)
{
    ull ans=2*(pow(2,mid)-1);
    ans-= pow(2,mid-1);
    return ans;
}

void bs(ull d, ll y){
    ull low=1,high=57;
    ull ans=60;
    while(low<=high)
    {
        ull mid=low+(high-low)/2;
        ull t=dis(mid);
        if(t<d)
        {
            low=mid+1;
        }
        else if(t>d)
        {
            high=mid-1;
            ans=min(ans,mid);
        }
        else
        {
            cout<<"Sim\n";
            mid--;
            if(mid%2==0)
            {
                cout<<y- pow(2,mid);
            }
            else
            {
                cout<<y+ pow(2,mid);
            }
            return;
        }
    }
    ull tmp= dis(ans)-d;
    ull _xtmp = pow(2,ans-1);
    ull xtmp = _xtmp + _xtmp/2;
    ull o = xtmp - tmp;

    if(o > (_xtmp/2 + _xtmp/4)){
        cout << "Sim\n";
        o -= _xtmp/2;
        if((ans - 1) % 2 ){
            cout << y + (ll)(o);
        }
        else{
            cout << y - (ll)(o);
        }
        return;
    }
    cout<<"Nao";
}


void solve()
{
    ull d;
    ll y;
    cin>>d>>y;
    bs(d,y);

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