//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;


int main(void){
    ios_base::sync_with_stdio(false) ;

    int n ;
    cin >> n ;
    double a , b , c = 0 ;
    double s = 0 ;
    for(int i = 0 ; i<n;  i++){
        cin >> a >> b ;
        c += a*b ;
        s+= b ;
    }

    printf("%.3f",c) ;

}
