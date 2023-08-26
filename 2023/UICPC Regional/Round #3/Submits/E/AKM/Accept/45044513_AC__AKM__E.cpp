//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

double dist(double a , double b , double c , double d ){
    return (a - c) * (a-c) + (b-d) * (b-d) ;
}

int main(void){
    ios_base::sync_with_stdio(false) ;
    int n , len , kasr ;
    cin >> n ;
    string str ;

    while (n--) {
        cin >> str ;
        len = str.length()  ;
        len = sqrt(len) ;
        kasr = 0 ;

        while (kasr<len) {
            for(int i = len-1 ; i<len*len ; i+=len){
                cout << str[i-kasr] ;
            }
            kasr++ ;
        }

        cout << '\n' ;

    }


    return 0 ;
}
