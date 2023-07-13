//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

int main(void){
    ios_base::sync_with_stdio(false) ;

    ll n ;
    cin >> n ;

    ll ans = 0 ;
    ll a;
    priority_queue<ll> vect  ;
    ll arr[n] ;
    for(ll i = 0 ; i<n; i++){
        cin >> a ;
        vect.push(a) ;

    }

    for(ll i=0 ; i<n ; i++){

        arr[i] = vect.top() ;
        vect.pop() ;
    }

    for(ll i = 0 ; i<n ; i++){

        if(i+1>=arr[i]){
            ans = arr[i] ;
            break;
        }
    }
    cout << ans ;

}
