#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> num(n);
    for(ll i=0;i<n;i++){
        cin >> num[i];
    }
    bool f = false;
    bool ok = true;
    sort(num.begin(),num.end());
    for(ll i=0;i<n;i++){
        
        for (ll j = n-1;j>i+1;j--){
            if(i >=j){
                ok = false;
                break;
            }
            ll c = j-1;
            
            if(num[i] + num[c] > num[j]){
                cerr<<num[i]<<" "<<num[c]<<" "<<num[j]<<endl;
                f = true;
                break;
            }

        }
        if(!ok) break;
        if(f) break;
    }
    if(f) cout << "possible" << endl;
    else cout << "impossible" << endl;

}