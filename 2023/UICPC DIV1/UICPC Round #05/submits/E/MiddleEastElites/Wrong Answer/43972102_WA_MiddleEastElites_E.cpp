//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

int main(void){
    ios_base::sync_with_stdio(false) ;

    int n ;
    cin >> n ;
    string str ;
    for(int i= 0 ; i<n; i++){
        cin >> str ;
        for(int j=0 ; j<3 ; j++)
            cout << str[j] ;
        for(int j=2 ; j>= 0 ; j--)
            cout << str[j] ;
        cout << '\n' ;
    }
}

