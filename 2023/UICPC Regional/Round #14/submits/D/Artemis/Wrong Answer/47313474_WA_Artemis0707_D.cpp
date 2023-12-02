#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<pair<ll,ll>> places(n+2);
        for(ll i = 0; i < n+2; i++){
            ll x,y;
            cin >> x >> y;
            places[i] = {x,y};
        }
        bool ok = true;
        for(ll i=1;i<n+2;i++){
            ll dist = abs(places[i].first-places[i-1].first)+abs(places[i].second-places[i-1].second);
            if(dist>1000){
                cout << "sad" << endl;
                ok = false;
                break;
            }

        }
        if(ok){
            cout << "happy" << endl;
        }

    }
    return 0;
}