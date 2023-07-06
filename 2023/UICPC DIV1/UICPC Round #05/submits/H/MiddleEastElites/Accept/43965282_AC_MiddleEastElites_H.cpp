//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;



int main(void){

    int t ;
    cin >> t ;
    double a , b ;
    double c , d ;
    for(int i=0 ; i<t ; i++){
        cin >> a >> b  ;
        c = 60*a /b ;
        d = 60 / b ;
        printf("%.4f",c-d) ;
        cout << ' ' ;
        printf("%.4f",c) ;
        cout << ' ' ;
        printf("%.4f",c+d) ;
        cout << endl ;
    }
    return 0 ;
}
