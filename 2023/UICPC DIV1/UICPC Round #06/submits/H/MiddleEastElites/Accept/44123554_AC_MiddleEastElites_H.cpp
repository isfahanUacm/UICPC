//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

int main(void){
    ios_base::sync_with_stdio(false) ;

    double a, b,c, d ;
    cin >> a >> b >> c >> d ;

    ll ans = ceil(d/b) ;

    ans *= a ;
    double az = int(d) % int(b) ;

    if(az){
        az = b - az ;
    }

    az *= a ;

    c -= az ;
    c = max(int(c),0) ;

    ans += ceil(c/b) ;

    cout << ans ;
}

