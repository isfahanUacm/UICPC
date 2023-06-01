//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;


int main(void){
    int n ;
    cin >> n ;
    int x[n] ;
    int y[n] ;
    for(int i=0 ; i<n ; i++)
        cin >> x[i] >> y[i] ;
    sort(x,x+n) ;
    sort(y,y+n) ;
    long long int sum = 0 ;
    int zarib = n-1 ;
    for(int i=n-1 ; i>=0 ; i--){
        sum += zarib * x[i] ;
        sum += zarib * y[i] ;
        zarib -= 2 ;
    }
    cout  << sum << '\n' ;
    return 0 ;
}
