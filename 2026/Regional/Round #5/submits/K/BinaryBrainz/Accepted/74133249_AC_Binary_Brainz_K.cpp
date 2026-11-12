#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    ll n,q;
    cin >> n>>q;
    ll sum=0;
    vector<ll> v(n);
for (ll i = 0; i < n; i++) {
    cin >> v[i];
    sum+=v[i];
}
    ll t=0;
    for (ll i = 0; i < q; i++) {
        cin >> t;
        if (t==1) {
            ll l,r,x;
            cin >> l >> r >> x;
            for (ll j = l-1; j <= r-1; j++) {
                v[j] = v[j]%x;
            }
        }
        else if (t==2) {
            ll l,r,x;
            cin >> l >> r >> x;
            for (ll j = l-1; j <= r-1; j++) {
                v[j] = max(v[j],x);
            }
        }
        else {
            ll l,r;
            cin >> l >> r;
            ll sm=0;
            for (ll j = l-1; j <= r-1; j++) {
                sm+=v[j];
            }
            cout << sm << endl;
        }
    }
    return 0;
}