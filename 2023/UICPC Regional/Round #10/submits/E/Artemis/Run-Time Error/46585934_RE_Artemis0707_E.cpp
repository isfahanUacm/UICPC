#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n = 0;
    cin >> n;
    string a,b;
    cin >> a>> b;

    ll i =0;
    ll j=0;
    string ans = "";

    while(ans.length() < n/2){
        if(a[i] == b[j]){
            ans += a[i];
            i++;
            j++;
        }
        else if(i < j){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<ans<<endl;



}