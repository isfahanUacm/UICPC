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
    ll ok = 0;
    if (q ==1 ){
        cout<<"no"<<endl;
        return 0;
    }
    for(auto v:pr){
        if(q%v ==0){
            while(q % v == 0){
                q /= v;
                ok =1;
            }
            if(q==1){
                ok = 2;
            }
            else{
                break;
            }
        }
    }
    
    if(ok == 2) cout << "yes" << endl;
    else if(ok == 1) cout << "no" << endl;
    else cout << "yes" << endl;
    return 0;
}