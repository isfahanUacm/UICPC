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
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%2==0)
    {
        cout<<n;
    }
    else cout<<0;
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
