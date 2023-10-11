#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mx = 1e5 + 10;
bool is_pr[mx];
vector<ll> pr;

int main(){

    for(ll i=2;i<mx;i++){
        if(is_pr[i]) continue;
        pr.push_back(i);
        for(ll j = i+i;j<mx;j+=i){
            is_pr[j] = 1;
        }
    }

    ll q;
    cin >> q;
    bool ok = 0;
    for(auto v:pr){
        if(q%v ==0){
            while(q % v == 0){
                q /= v;
            }
            if(q==1){
                ok = 1;
            }
            else{
                break;
            }
        }
    }
    if(q > 1e5) ok = 1;
    if(ok) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}