#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll c;
    cin >> c;
    ll n; cin>>n;
    vector<ll>v(n);
    set<ll> need;

    for(int i =0 ; i< n ; i++){
        cin >> v[i];
        if(c%v[i])
            continue;
        need.insert(c/v[i]);
    }

    ll a,b;

    for(int i=0 ;i < n ; i++){
        auto x = need.find(v[i]);
        if(x != need.end())
            {
            a = v[i];
            b = c / v[i];
        }
    }
    cout << min(a,b) <<' ' << max(a,b);
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        if(t!=0)
            cout<<endl;
    }
}

