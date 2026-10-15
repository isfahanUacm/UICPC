#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vl = vector<long long>;

set<int>st;
bool is_prime(int n)
{
    if(st.find(n)!=st.end())
        return true;
    return false;
}
bool prime(int n)
{
    if(n<=1) return false;
    for (int i = 2; i*i <=n ; ++i) {
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

void solve()
{
    int m;
    cin >> m;
    int ans = 0;
    for(auto &itr: ps){
        if(itr > m){
            break;
        }

        int cnt = 0;
        ll p = itr;
        while(p <= m){
            p *= p;
            cnt++;
        }
        ans+= cnt;
    }
    cout << ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    spf_gen();
    cin >> t;
    while (t--) {
        solve();
        if(t)cout<<endl;
    }
    return 0;
}