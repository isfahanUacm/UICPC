//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

int arr[100] ;

int main(void){
    ios_base::sync_with_stdio(false) ;
    int n , l , p ;
    cin>> n >> l >> p ;
    ll x ;
    int temp , t ;
    ll maxi = 0 ;
    for(int i=0 ; i<p ; i++){
        cin >> x ;
        temp = x/l ;
        arr[temp]++ ;
        temp = x%l ;
        t = abs(l/2 - temp) ;
        if(t>maxi)
            maxi = t ;
    }
    int te = 0 ;
    for(int i=0 ; i<n ; i++)
        if(arr[i]>te)
            te = arr[i] ;
    cout << maxi << '\n' << te << '\n' ;

    return 0 ;
}
