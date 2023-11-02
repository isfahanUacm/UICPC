#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n = 0;
    cin >> n;
    string a,b;
    cin >> a;
    cin >> b;
    ll i=0;
    ll j=0;
    string ans = "";
    while(true){
        //cerr<<ans<<endl;
        if (n%2 == 0 && ans.length() >= n/2){
            break;
        }
        else if(ans.length() > n/2){
            break;
        }
        bool ok = false;
        for(ll t=0;t<5;t++){
            if(a[i] == b[j+t]){
                ans += a[i];
                i++;
                j += t + 1;
                ok = true;
                break;
            }
        }
        if(!ok){
            for(ll t=0;t<5;t++){
                if(a[i+t] == b[j]){
                    ans += b[j];
                    j++;
                    i += t + 1;
                    ok = true;
                    break;
                }
        }
        if(!ok){
            if(i <= j){
                i++;
            }
            else{
                j++;
            }
        }
        }
    }
    cout<<ans;
    return 0;
}