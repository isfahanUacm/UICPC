#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n1,n2;
    cin >> n1 >> n2;

    ll tn1 = n1;
    ll ans = 0;
    while(tn1 != n2){
        tn1++;
        tn1 %= 360;
        ans++;
    }
    tn1 = n1;
    ll ans2 = 0;
    while(tn1 != n2){
        tn1--;
        if(tn1 < 0) tn1 += 360;
        ans2--;
    }
    cerr<<ans<<" "<<ans2<<endl;
    if(abs(ans2) < ans){
        cout<<ans2<<endl;
    }
    else{
        cout<<ans<<endl;
    }



    return 0;
}