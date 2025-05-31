#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
struct pairs{
    char c;
    ll ind;
};
set<ll> st;
bool prime(ll n)
{
    for(auto &itr : st){
        if(n % itr == 0){
            return false;
        }
    }
    st.insert(n);
    return true;
}
void solve() {
    ll n,r;
    cin>>n>>r;
    ll a= sqrt(n);
    ll b= sqrt(r);
    if(a*a== sqrt(n))
        cout<<b-a+1;
    else
        cout<<b-a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
        if (t) cout << '\n';
    }
    return 0;
}
