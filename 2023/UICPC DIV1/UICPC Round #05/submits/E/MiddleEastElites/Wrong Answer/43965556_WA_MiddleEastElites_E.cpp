//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;



int main(void){

    int n;

    string num ;
    cin >> n ;
    for(int i=0 ; i<n;  i++){
        cin >> num ;
        for(int i=0 ; i<3 ; i++)
            cout << num[i] ;
        for(int i=2 ;i>=0 ; i--)
            cout << num[i] ;
        cout << '\n' ;

    }
    return 0 ;
}
