///In he nme of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;

int main()
{
    ios_base::sync_with_stdio(false) ;
    ll n ;
    cin >> n ;
    if(n%4==2){
        cout << "impossible" << '\n' ;
    }
    else{
        if(n%2==1){
            cout << (n+1)/2 << ' ' << n/2  << '\n';
         }
        else{
            n /= 4 ;
            ll a = n+1 ;
            ll b = n-1 ;
            cout << a << ' ' << b << '\n' ;
         }
    }
    return 0;
}
