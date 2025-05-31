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
    ll n,t,k,d;
    cin>>n>>t>>k>>d;
    ll div = n/k + ((n % k) ? 1 : 0);
    if(d+t<div*t)
        cout<<"YES";
    else cout<<"NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
        if (t) cout << '\n';
    }
    return 0;
}
